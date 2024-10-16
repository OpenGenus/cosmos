/* Part of Cosmos by OpenGenus Foundation */
function factorial(n) {
  return n === 0 ? 1 : n * factorial(n - 1);
}

const num = 3;
console.log(factorial(num));
