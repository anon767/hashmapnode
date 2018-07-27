# Native Hashmap  
  
Simple but fast Hashmap for NodeJS. Implemented in C++.

## Install

```
npm i nativehashmap
```
## Sample Usage

```
var hashmap=require("nativehashmap");
hashmap.add("key", "value");
console.log(hashmap.get("key"));
```

## Metrics

1. writing is about 2x faster
2. reading is 15% faster