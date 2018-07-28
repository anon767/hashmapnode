# Native Hashmap  
  
Simple but fast Hashmap for NodeJS. Implemented in C++.

## Install
due to the implementation in C++, a C++-Compiler is required and on certain OS libuv.


```
npm i nativehashmap
```
## Sample Usage

```javascript
var hashmap=require("nativehashmap");
hashmap.add("key", "value");
console.log(hashmap.get("key"));
```

Its possible to store JSON objects like:

```javascript
addon.add("object", JSON.stringify({o:"test"}));
console.log(JSON.parse(addon.get("object")).o === "test");
```

Also you can fetch values Async

```javascript
addon.add("object", JSON.stringify({o:"test"}));
addon.getAsync("object",function(value){
   console.log(JSON.parse(value).o === "test"); 
});
```

Check out the Tests and Benchmarks for further examples

## Metrics

1. writing is about 2x faster
2. reading is 15% faster

compared to npm package "hashmap"
and still 2x faster in writing than ordinary JS-Array-Access. 
