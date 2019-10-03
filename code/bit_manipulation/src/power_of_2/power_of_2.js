/*

    Part of Cosmos by OpenGenus Foundation
    Created by Jiraphapa Jiravaraphan on 14/10/2017 
    Check if a number is a power of 2 - javascript implementation

*/

function isPowerOf2(num) {
  if (typeof num === "number") return num && (num & (num - 1)) === 0;
}

console.log(isPowerOf2(64));
