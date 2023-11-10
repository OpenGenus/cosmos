let num = 600851475143;
let highestPrimeFactor = 0;
let currentFactor = 2;

while (num > highestPrimeFactor) {
  if (num % currentFactor === 0) {
    highestPrimeFactor = currentFactor;
    num /= currentFactor;
  } else {
    ++currentFactor;
  }
}

console.log(highestPrimeFactor);
