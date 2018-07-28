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

auto *kvsimpl = new KeyValueStoreImpl<const std::string, std::string>();
KeyValueStore<const std::string, std::string> *kvs = kvsimpl;

auto isolate = Isolate::GetCurrent();

static void inline Add(const v8::FunctionCallbackInfo<v8::Value> &info) {
    String::Utf8Value keyUtf8(isolate, info[0]->ToString());
    const std::string keyString = std::string(*keyUtf8);
    String::Utf8Value valueUtf8(isolate, info[1]->ToString());
    const std::string valueString = std::string(*valueUtf8);
    kvs->add(keyString, valueString);
}

static void inline Get(const v8::FunctionCallbackInfo<v8::Value> &info) {
    String::Utf8Value keyUtf8(isolate, info[0]->ToString());
    const std::string keyString = std::string(*keyUtf8);
    const std::string outputString = kvs->get(keyString);
    const char *outputCString = outputString.c_str();
    const Local<String> output = String::NewFromUtf8(isolate, outputCString);
    info.GetReturnValue().Set(output);
}

void init(Handle<Object> exports) {
    exports->Set(String::NewFromUtf8(isolate, "add"),
                 FunctionTemplate::New(isolate, Add)
                         ->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "get"),
                 FunctionTemplate::New(isolate, Get)
                         ->GetFunction());
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)