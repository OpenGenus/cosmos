let num = 600851475143;
let highestPrimeFactor = 0;
let currentFactor = 2;

while (num !== 1) {
  if (num % currentFactor === 0 && currentFactor > highestPrimeFactor) {
    highestPrimeFactor = currentFactor;
    num /= currentFactor;
    currentFactor = 2;
  }
  else {
    ++currentFactor; 
  }
}

console.log(highestPrimeFactor);
