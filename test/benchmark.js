'use strict';

const addon = require("../index.js");
let test1 = [];
const amount = 5000000;

console.time('addCpp');
for (let i = 0; i < amount; i++) {
    addon.add("test" + i, "dsfgsdfg " + i);
}
console.timeEnd('addCpp');
console.time('getCpp');
for (let i = 0; i < amount; i++) {
    addon.get("test" + i)
}
console.timeEnd('getCpp');
console.time('addJS');
for (let i = 0; i < amount; i++) {
    test1["test" + i] = "dsfgsdfg " + i;
}
console.timeEnd('addJS');


console.time('getJS');
for (let i = 0; i < amount; i++) {
    test1["test" + i]
}
console.timeEnd('getJS');


console.time('getAsyncCpp');
for (let i = 0; i < amount; i++) {
    addon.getAsync("test" + i, function (value) {
    })
}
console.timeEnd('getAsyncCpp');