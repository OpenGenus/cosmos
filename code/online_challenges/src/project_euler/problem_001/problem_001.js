/*

// online challenges | project euler | problem 001 | problem 001 | JAVASCRIPT
// Part of Cosmos by OpenGenus Foundation

*/


let sum = 0;
for (let i = 0; i < 1000; i += 1) {
  if (i % 3 === 0 || i % 5 === 0) {
    sum += i;
  }
}
console.log(sum);
