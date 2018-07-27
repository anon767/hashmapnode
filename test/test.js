'use strict';

const addon = require("../index.js");
let test1 = [];


console.time('addCpp');
for (let i = 0; i < 1000000; i++) {
    addon.add("test" + i, "dsfgsdfg " + i);
}
console.timeEnd('addCpp');
console.time('addJS');
for (let i = 0; i < 1000000; i++) {
    test1["test" + i] = "dsfgsdfg " + i;
}
console.timeEnd('addJS');
console.time('getCpp');
for (let i = 0; i < 1000000; i++) {
    let b = addon.get("test" + i)
}
console.timeEnd('getCpp');
console.time('getJS');
for (let i = 0; i < 1000000; i++) {
    let b = test1["test" + i]
}
console.timeEnd('getJS');

console.log("overwite");
{
    addon.add("test", "a");
    addon.add("test", "b");
    console.assert(addon.get("test") === "b", "Should overwrite to b");
}

console.log("empty");
{

    console.assert(addon.get("fdghdfghdfghdfgh").length < 2, "If nothing found should be empty");
}