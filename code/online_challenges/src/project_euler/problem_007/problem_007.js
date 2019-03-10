/* Part of Cosmos by OpenGenus Foundation */

const primes = [];
let n = 2;

while (primes.length < 10001) {
  // if this number is not divisible by any prime currently in the array
  if (primes.reduce((isPrime, prime) => isPrime && n % prime !== 0, true)) {
    primes.push(n);
  }

  n++;
}

console.log(primes[10000]);
