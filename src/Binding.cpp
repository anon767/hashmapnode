#include <node/node.h>
#include <node/v8.h>
#include <uv.h>
#include <string>
#include "KeyValueStore.h"
#include "KeyValueStoreImpl.h"
#include "KeyValueStoreImpl.cpp"
#include <iostream>
#include <node/node_object_wrap.h>

#if defined _WIN32
#include <windows.h>
#else

#include <unistd.h>

#endif

auto *kvsimpl = new KeyValueStoreImpl<const std::string, std::string>();
KeyValueStore<const std::string, std::string> *kvs = kvsimpl;
auto isolate = v8::Isolate::GetCurrent();

using namespace v8;

struct async_req {
    uv_work_t req;
    std::string input;
    std::string output;
    v8::Isolate *isolate;
    v8::Persistent <v8::Function> callback;
    node::async_context context;
};

void DoAsync(uv_work_t *r) {
    async_req *req = reinterpret_cast<async_req *>(r->data);
    req->output = kvs->get(req->input);
}

void AfterAsync(uv_work_t *r, int ignored) {
    async_req *req = reinterpret_cast<async_req *>(r->data);
    v8::Isolate *isolate = req->isolate;
    v8::HandleScope scope(isolate);
    v8::Local <v8::Value> argv[1] = {
            String::NewFromUtf8(isolate, req->output.c_str())
    };
    v8::TryCatch try_catch(isolate);
    v8::Local <v8::Object> global = isolate->GetCurrentContext()->Global();
    v8::Local <v8::Function> callback =
            v8::Local<v8::Function>::New(isolate, req->callback);
    callback->Call(global, 1, argv);
    node::EmitAsyncDestroy(isolate, req->context);
    req->callback.Reset();
    delete req;
}

void GetAsync(const v8::FunctionCallbackInfo <v8::Value> &args) {
    v8::Isolate *isolate = args.GetIsolate();
    async_req *req = new async_req;
    req->req.data = req;
    String::Utf8Value keyUtf8(isolate, args[0]->ToString());
    const std::string keyString = std::string(*keyUtf8);
    req->input = keyString;
    req->isolate = isolate;
    req->context = node::EmitAsyncInit(isolate, v8::Object::New(isolate), "test");
    v8::Local <v8::Function> callback = v8::Local<v8::Function>::Cast(args[1]);
    req->callback.Reset(isolate, callback);
    uv_queue_work(node::GetCurrentEventLoop(isolate),
                  &req->req,
                  DoAsync,
                  (uv_after_work_cb) AfterAsync);
}

static void inline Add(const v8::FunctionCallbackInfo <v8::Value> &info) {
    String::Utf8Value keyUtf8(isolate, info[0]->ToString());
    const std::string keyString = std::string(*keyUtf8);
    String::Utf8Value valueUtf8(isolate, info[1]->ToString());
    const std::string valueString = std::string(*valueUtf8);
    kvs->add(keyString, valueString);
}

static void inline Get(const v8::FunctionCallbackInfo <v8::Value> &info) {
    String::Utf8Value keyUtf8(isolate, info[0]->ToString());
    const std::string keyString = std::string(*keyUtf8);
    const std::string outputString = kvs->get(keyString);
    const char *outputCString = outputString.c_str();
    const Local <String> output = String::NewFromUtf8(isolate, outputCString);
    info.GetReturnValue().Set(output);
}

void init(Handle <Object> exports) {
    exports->Set(String::NewFromUtf8(isolate, "add"),
                 FunctionTemplate::New(isolate, Add)
                         ->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "get"),
                 FunctionTemplate::New(isolate, Get)
                         ->GetFunction());
    NODE_SET_METHOD(exports, "getAsync", GetAsync);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init
)