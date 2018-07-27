'use strict';
var nativehashmap = null;
if (process.platform === "win32" && process.arch === "x64") {
    nativehashmap = null;
    console.exception("Key Value Store only Linux compatible");
} else if (process.platform === "win32" && process.arch === "ia32") {
    nativehashmap = null;
    console.exception("Key Value Store only Linux compatible");
} else {
    nativehashmap = require('./build/Release/keyvaluestore');
}

module.exports = nativehashmap;