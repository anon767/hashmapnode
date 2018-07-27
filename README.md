# Native Hashmap  
  
Simple but fast Hashmap for NodeJS. Implemented in C++.

## Install

```
npm i hashmapnative
```

## Sample Usage

```
var hashmap=require("nativehashmapnative");
hashmap.add("key", "value");
hashmap.get("key")
```

## Metrics

1. writing is about 2x faster
2. reading is 15% faster