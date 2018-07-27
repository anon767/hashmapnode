'use strict';
var kvs = null;
if (process.platform === "win32" && process.arch === "x64") {
    kvs = null;
    console.exception("Key Value Store only Linux compatible");
} else if (process.platform === "win32" && process.arch === "ia32") {
    kvs = null;
    console.exception("Key Value Store only Linux compatible");
} else {
    kvs = require('./build/Release/keyvaluestore');
}

module.exports = kvs;