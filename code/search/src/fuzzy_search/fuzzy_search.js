//
// A node module that executes the Fuzzy Search algorithm
//
// Usage:
// const fs = require('./fuzzySearch');
// console.log(fs('A', 'ACC'))
//

"use strict";

function fuzzySearch(needle, haystack) {
  var haystack_length = haystack.length;
  var needle_length = needle.length;
  if (needle_length > haystack_length) {
    return false; // return false if Needle is longer than haystack
  }
  if (needle_length === haystack_length) {
    return needle === haystack;
  }
  mainLoop: for (var i = 0, j = 0; i < needle_length; i++) {
    var nth_character = needle.charCodeAt(i);
    while (j < haystack_length) {
      if (haystack.charCodeAt(j++) === nth_character) {
        continue mainLoop;
      }
    }
    return false;
  }
  return true;
}

module.exports = fuzzysearch;
