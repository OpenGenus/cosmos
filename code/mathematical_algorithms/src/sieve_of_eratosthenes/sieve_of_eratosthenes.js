class SieveOfEratosthenes {
  /**
   * @constructor
   * @param {number} max - max number to test up to
   * Part of Cosmos by OpenGenus Foundation
   */
  constructor(max) {
    this._max = max;
    this._sqrtMax = Math.ceil(Math.sqrt(this._max));

    // Get an array from number 2 up to max. Start from 2 because 0 and 1
    // are not primes and do not need to be evaluated.
    this._storage = Array.from({ length: max - 1 }, (k, v) => v + 2);
  }

  _isPrime(num) {
    for (let i = 2; i < this._sqrtMax; i++) {
      if (num % i === 0 && num !== i) {
        return false;
      }
    }
    return true;
  }

  /**
   * start - determine all primes
   * @return {array} an array of all prime numbers from 2 to max.
   */
  start() {
    this._storage = this._storage.filter(num => {
      return this._isPrime(num);
    });

    return this._storage;
  }
}

////////////
// TESTS: //
////////////

// All valid prime numbers up to 1000
const primeNums = [
  2,
  3,
  5,
  7,
  11,
  13,
  17,
  19,
  23,
  29,
  31,
  37,
  41,
  43,
  47,
  53,
  59,
  61,
  67,
  71,
  73,
  79,
  83,
  89,
  97,
  101,
  103,
  107,
  109,
  113,
  127,
  131,
  137,
  139,
  149,
  151,
  157,
  163,
  167,
  173,
  179,
  181,
  191,
  193,
  197,
  199,
  211,
  223,
  227,
  229,
  233,
  239,
  241,
  251,
  257,
  263,
  269,
  271,
  277,
  281,
  283,
  293,
  307,
  311,
  313,
  317,
  331,
  337,
  347,
  349,
  353,
  359,
  367,
  373,
  379,
  383,
  389,
  397,
  401,
  409,
  419,
  421,
  431,
  433,
  439,
  443,
  449,
  457,
  461,
  463,
  467,
  479,
  487,
  491,
  499,
  503,
  509,
  521,
  523,
  541,
  547,
  557,
  563,
  569,
  571,
  577,
  587,
  593,
  599,
  601,
  607,
  613,
  617,
  619,
  631,
  641,
  643,
  647,
  653,
  659,
  661,
  673,
  677,
  683,
  691,
  701,
  709,
  719,
  727,
  733,
  739,
  743,
  751,
  757,
  761,
  769,
  773,
  787,
  797,
  809,
  811,
  821,
  823,
  827,
  829,
  839,
  853,
  857,
  859,
  863,
  877,
  881,
  883,
  887,
  907,
  911,
  919,
  929,
  937,
  941,
  947,
  953,
  967,
  971,
  977,
  983,
  991,
  997
];

// Test cases:
// All test cases should return "test-X is true"
const testNums = [1, 30, 100, 300, 600, 1000];

testNums.forEach((max, idx) => {
  const sieve = new SieveOfEratosthenes(max);
  const allPrimes = sieve.start();

  const diff = allPrimes.filter(num => {
    return primeNums.indexOf(num) === -1;
  });

  console.log(`test-${idx} is ${diff.length === 0}`);
});
