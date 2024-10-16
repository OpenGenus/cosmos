/**
 * bloom_filter.js
 * @author Sidharth Mishra
 * @description Bloom filter in Javascript(Node.js), to be used with Node.js for testing. For `OpenGenus/cosmos`
 * @created Wed Oct 18 2017 19:31:29 GMT-0700 (PDT)
 * @copyright 2017 Sidharth Mishra
 * @last-modified Wed Oct 18 2017 19:31:32 GMT-0700 (PDT)
 */

/**
 * bf -- Bloom Filter utilities, uses FNV and FNV-1a hash algorithms for now.
 * Future work: Added hash mix with Murmur3 hash
 *
 * Addition into bloom filter: Time Complexity : O(k) where k = number of hash functions
 * Checking membership: Time Complexity : O(k) where k = number of hash functions
 */
(function(bfilter) {
  /**
   * Makes a new bloom filter. Uses FNV Hash as the hash function. This implementation uses only
   * FNV Hash functions for now.
   * FNV hash versions:
   * -> FNV
   * -> FNV 1a
   *
   * :Future work:
   * Add Murmur3 hash function.
   *
   * @param {number} m The number of bits in the Bit Vector backing the bloom filter
   * @param {[Function]} k the hash functions to be used
   *
   * @returns {bfilter.BloomFilter} a bloom filter with m bits and k hash functions
   */
  bfilter.BloomFilter = function BloomFilter(m, k) {
    if (
      arguments.length < 2 ||
      undefined == m ||
      undefined == k ||
      undefined == k.length ||
      k.length == 0 ||
      typeof k !== "object"
    ) {
      throw new Error("Couldn't construct a bloom filter, bad args");
    }
    // count of number of elements inserted into the bloom filter
    this.nbrElementsInserted = 0;
    this.bitVector = []; // the bit vector
    this.hashFunctions = k; // the list of hash functions to use for adding and testing membership
    // make the bit vector with m bits
    for (let i = 0; i < m; i++) {
      this.bitVector.push(false);
    }
    for (let i = 0; i < this.hashFunctions.length; i++) {
      if (typeof this.hashFunctions[i] !== "function") {
        throw new Error("Hash function is not a function");
      }
    }
  };

  /**
   * FNV hashing using the FNVHash - v1a see link: http://isthe.com/chongo/tech/comp/fnv/#history,
   * uses:
   * 32 bit offset basis = 2166136261
   * 32 bit FNV_prime = 224 + 28 + 0x93 = 16777619
   * @param {Buffer} toBeHashed The element to be hashed, Node.js buffer
   */
  bfilter.fnvHash1a = function(toBeHashed) {
    const OFFSET_BASIS_32 = 2166136261;
    const FNV_PRIME = 16777619;
    let hash = OFFSET_BASIS_32; // 32 bit offset basis
    // or each octet_of_data to be hashed
    // toBeHashed is a Buffer that has octets of data to be hashed
    for (let i = 0; i < toBeHashed.length; i++) {
      hash = hash ^ toBeHashed[i];
      hash = hash * FNV_PRIME;
    }
    // since hash being returned is negative most of the times
    return Math.abs(hash);
  };

  /**
   * FNV hashing using the FNVHash - v1 see link: http://isthe.com/chongo/tech/comp/fnv/#history,
   * uses:
   * 32 bit offset basis = 2166136261
   * 32 bit FNV_prime = 224 + 28 + 0x93 = 16777619
   * @param {Buffer} toBeHashed The element to be hashed, Node.js buffer
   */
  bfilter.fnvHash = function(toBeHashed) {
    const OFFSET_BASIS_32 = 2166136261;
    const FNV_PRIME = 16777619;
    let hash = OFFSET_BASIS_32; // 32 bit offset basis
    // or each octet_of_data to be hashed
    // toBeHashed is a Buffer that has octets of data to be hashed
    for (let i = 0; i < toBeHashed.length; i++) {
      hash = hash * FNV_PRIME;
      hash = hash ^ toBeHashed[i];
    }
    // since hash being returned is negative most of the times
    return Math.abs(hash);
  };

  /**
   * Adds the element to the bloom filter. When an element is added to the bloom filter, it gets through
   * the k different hash functions; i.e it gets hashed k times.
   * T:: O(k) operation
   * @param {string} element The element is converted bits and then hashed k times before getting added
   * to the bit vector.
   */
  bfilter.BloomFilter.prototype.add = function(element) {
    // console.log(JSON.stringify(this));
    if (typeof element !== "string") {
      element = String(element);
    }
    let buffE = Buffer.from(element); // get the element buffer
    let hash = null;
    for (let i = 0; i < this.hashFunctions.length; i++) {
      hash = this.hashFunctions[i](buffE);
      // update the bit vector's index
      // depending on the hash value
      this.bitVector[hash % this.bitVector.length] = true;
    }
    this.nbrElementsInserted += 1;
  };

  /**
   * Check if the element is in the bloom filter.
   * T:: O(k) operation
   * @param {string} element The element that needs to get its membership verified
   */
  bfilter.BloomFilter.prototype.check = function(element) {
    if (typeof element !== "string") {
      element = String(element);
    }
    let buffE = Buffer.from(element); // get the element buffer
    let hash = null;
    let prob = true;
    for (let i = 0; i < this.hashFunctions.length; i++) {
      hash = this.hashFunctions[i](buffE);
      // checking membership by ANDing the bits in the bitVector
      prob = prob && this.bitVector[hash % this.bitVector.length];
    }
    if (prob) {
      return {
        probability: calcProb(
          this.bitVector.length,
          this.hashFunctions.length,
          this.nbrElementsInserted
        ),
        isMember: prob
      };
    } else {
      return {
        probability: 1,
        isMember: prob
      };
    }
  };

  /**
   * * Computes the probabilty of membership in the bloom filter = (1-e^-kn/m)^k
   * where ^ is exponentation
   *
   * @param {*} m The number of bits in the bit vector
   * @param {*} k The number of hash functions
   * @param {*} n The number of elements added to the bloom filter
   *
   * @returns {number} The probability of membership
   */
  function calcProb(m, k, n) {
    return Math.pow(1 - Math.exp((-1 * k * n) / m), k);
  }
})((bf = {}));

// exports the bf -- bloom filter utilities
module.exports.bf = bf;

/**
 * Tests
 *
 * @param {number} m The size of bit vector backing the bloom filter
 * @param {[Function]} k The nunber of times the element needs to be hashed
 */
function test(m, k) {
  let bloomFilter = new bf.BloomFilter(m, k);
  bloomFilter.add("hello");
  bloomFilter.add("helloWorld");
  bloomFilter.add("helloDear");
  bloomFilter.add("her");
  bloomFilter.add("3456");
  console.log(
    `hello in bloom filter = ${JSON.stringify(bloomFilter.check("hello"))}`
  );
  console.log(
    `helloWorld in bloom filter = ${JSON.stringify(
      bloomFilter.check("helloWorld")
    )}`
  );
  console.log(
    `helloDear in bloom filter = ${JSON.stringify(
      bloomFilter.check("helloDear")
    )}`
  );
  console.log(
    `world in bloom filter = ${JSON.stringify(bloomFilter.check("world"))}`
  );
  console.log(
    `123 in bloom filter = ${JSON.stringify(bloomFilter.check("123"))}`
  );
  console.log(
    `Number(3456) in bloom filter = ${JSON.stringify(bloomFilter.check(3456))}`
  );
  console.log(
    `Number(3) in bloom filter = ${JSON.stringify(bloomFilter.check(3))}`
  );
  console.log(
    `Number(4) in bloom filter = ${JSON.stringify(bloomFilter.check(4))}`
  );
  console.log(
    `Number(5) in bloom filter = ${JSON.stringify(bloomFilter.check(5))}`
  );
  console.log(
    `Number(6) in bloom filter = ${JSON.stringify(bloomFilter.check(6))}`
  );
}

// some tests
console.log("---------- test 1 ----------");
try {
  test(32);
} catch (e) {
  console.log("Test 1 passed!");
}

console.log("---------- test 2 ----------");
try {
  test(4, [bf.fnvHash, 55]);
} catch (e) {
  console.log("Test 2 passed!");
}

console.log("---------- test 3 ----------");
try {
  test(15, [bf.fnvHash1a]);
  console.log("Test 3a passed! ---");
  test(15, [bf.fnvHash]);
  console.log("Test 3b passed!");
} catch (e) {
  console.log(e);
}

console.log("---------- test 4 ----------");
try {
  test(64, [bf.fnvHash1a]);
  console.log("Test 4 passed!");
} catch (e) {
  console.log(e);
}

console.log("---------- test 5 ----------");
try {
  test(32, [bf.fnvHash1a, bf.fnvHash1a, bf.fnvHash, bf.fnvHash1a]);
  console.log("Test 5 passed!");
} catch (e) {
  console.log(e);
}

console.log("---------- test 6 ----------");
try {
  test(32, 6);
} catch (e) {
  console.log("Test 6 passed!");
}

console.log("---------- test 7 ----------");
try {
  test(32, [bf.fnvHash1a, bf.fnvHash1a, bf.fnvHash1a, bf.fnvHash1a]);
  console.log("Test 7 passed!");
} catch (e) {
  console.log(e);
}

// console.log(bf.fnvHash(Buffer.from("hello")) % 15);
