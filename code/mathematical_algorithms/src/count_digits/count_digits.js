// Part of Cosmos by OpenGenus Foundation

function countDigits(n) {
  let numDigits = 0;
  let integers = Math.abs(n);

  if (n == 0) return 1;

  while (integers > 0) {
    integers = Math.floor(integers / 10);
    numDigits++;
  }
  return numDigits;
}

// Tests
console.log(countDigits(0)); // => 1
console.log(countDigits(2)); // => 1
console.log(countDigits(12)); // => 2
console.log(countDigits(887)); // => 3
