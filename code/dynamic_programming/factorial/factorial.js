// Part of Cosmos by OpenGenus Foundation 

function factorial(num) {
  if (num == 0) return 1;
  
  return num * factorial (num - 1);
}

let testVal = 5;
let fact = factorial(testVal);

console.log(`${testVal} factorial is ${fact}.`);
