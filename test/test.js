'use strict';

const addon = require("../index.js");


{
    addon.add("test", "a");
    addon.add("test", "b");
    console.assert(addon.get("test") === "b", "Should overwrite to b");
    console.log("Overwriting works - ✓");
}


{
    console.assert(addon.get("fdghdfghdfghdfgh").length < 2, "return should be empty");
    console.log("Empty Return works - ✓")
}


{
    addon.add("object", JSON.stringify({o: "test"}));
    console.assert(JSON.parse(addon.get("object")).o === "test", "Object is not accessible");
    console.log("JSON Object Accessibility works - ✓")
}