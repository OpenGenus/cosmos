/**
In mathematics an automorphic number (sometimes referred to as a circular number) is a number
whose square "ends" in the same digits as the number itself. 
For example, 5^2 = 25, 6^2 = 36, 76^2 = 5776, 376^2 = 141376,and 890625^2 = 793212890625, 
so 5, 6, 76 and 890625
*/

// Part of Cosmos by OpenGenus Foundation
const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question("Enter a Number: ", num => {
  if (automorphic(num)) console.log(`${num} is an automorphic number.`);
  else console.log(`${num} is not an automorphic number.`);
  rl.close();
});

function automorphic(num) {
  return Math.pow(num, 2) % Math.pow(10, num.toString().length) == num;
}
