/*
 * Part of Cosmos by OpenGenus Foundation
 * The Lonely Integer Problem
 * Given an array in which all the no. are present twice except one, find that lonely integer.
 */
function lonelyInt(arr) {
  var lonely = 0;
  arr.forEach(number => {
    lonely ^= number;
  });
  return lonely;
}

function test() {
  var test = [1, 1, 2, 4, 2];
  console.log(lonelyInt(test));
}

test();
