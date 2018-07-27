#include <node/node.h>
#include <node/v8.h>
#include <node/uv.h>
#include <string>
#include "KeyValueStore.h"
#include "KeyValueStoreImpl.h"
#include "KeyValueStoreImpl.cpp"
#include <iostream>
#include <node/node_object_wrap.h>

using namespace v8;

auto *kvsimpl = new KeyValueStoreImpl<std::string, std::string>();
KeyValueStore<std::string, std::string> *kvs = kvsimpl;


static void Add(const v8::FunctionCallbackInfo<v8::Value> &info) {


    String::Utf8Value keyUtf8(info[0]->ToString());
    std::string keyString = std::string(*keyUtf8);
    String::Utf8Value valueUtf8(info[1]->ToString());
    std::string valueString = std::string(*valueUtf8);
    kvs->add(keyString, valueString);

    info.GetReturnValue().Set(true);
}

static void Get(const v8::FunctionCallbackInfo<v8::Value> &info) {
    auto isolate = Isolate::GetCurrent();

    String::Utf8Value keyUtf8(info[0]->ToString());
    std::string keyString = std::string(*keyUtf8);

    info.GetReturnValue().Set(String::NewFromUtf8(isolate, kvs->get(keyString).c_str()));
}

void init(Handle<Object> exports, Local<Object> module, Local<Context> *context) {
    auto isolate = Isolate::GetCurrent();


    exports->Set(String::NewFromUtf8(isolate, "add"),
                 FunctionTemplate::New(isolate, Add)
                         ->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "get"),
                 FunctionTemplate::New(isolate, Get)
                         ->GetFunction());


}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)