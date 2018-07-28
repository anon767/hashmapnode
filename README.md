# Native Hashmap  
  
Simple but fast Hashmap for NodeJS. Implemented in C++.

## Install
due to the implementation in C++, a C++-Compiler is required and on certain OS libuv.


```
npm i nativehashmap
```
## Sample Usage

```
var hashmap=require("nativehashmap");
hashmap.add("key", "value");
console.log(hashmap.get("key"));
```

Its possible to store JSON objects like:

```
addon.add("object", JSON.stringify({o:"test"}));
console.log(JSON.parse(addon.get("object")).o === "test");
```


## Metrics

1. writing is about 2x faster
2. reading is 15% faster

than ordinary array usage or other hashmap libraries