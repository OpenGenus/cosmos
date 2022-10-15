# Sieve of Eratosthenes

Learn at [**OpenGenus IQ**](https://iq.opengenus.org/the-sieve-of-eratosthenes/)

The **Sieve of Eratosthenes** is used to find prime numbers from 2 up to some predefined integer n. While this seive is efficient, there are faster and more efficient sieves out there (see [Sieve of Atkin](https://github.com/OpenGenus/cosmos/tree/master/code/mathematical_algorithms/src/sieve_of_atkin)). However, this sieve is simple to understand and implement for finding prime numbers, and consequently acts as a good example of a what a sieve algorithm is.

When implemented correctly, the **Sieve of Eratosthenes** has a time complexity of $O(n\log{}n)$. In contrast to the brute force method, which has a time complexity of $O(n^2)$.

## Algorithm

The algorithm requires a binary array (which may be a packed bit array) representing the primality of each index from 2 to n. The array initially has all cells set to True (assuming all numbers are prime to start), and then any multiples of a given prime are set to False ("crossed out"). By the end, all multiplies of one or more primes will be eliminated, leaving only the prime numbers within the specified range. There are some tricks to the sieve that make it more than just a brute force elimination seive (as will be mentioned) but that's the core principle behind the sieve.

### Example

Suppose a range from 2 to 10...
1. Create an array for that given range (10 elements to start) `[ True, True, True, True, True, True, True, True, True, True ]`
2. Set the first element to False (since 1 is not prime) `[ False, True, True, True, True, True, True, True, True, True ]`
3. Start at the first True index (our first prime number) `[ False, (True), True, True, True, True, True, True, True, True ]`
4. Eliminate all multiples of that index starting from the square of the index (4, 6, 8, etc...) `[ False, True, True, False, True, False, True, False, True, False ]`
5. Move to the next True index (the next prime number)
6. Go to 4, repeating until we've reached the square root of n (in this case, the square root of 10)
7. We now have all the primes from 2 to n (2 to 10 in this case)

### Explanation

So why are we starting at the square of primes? Why are we stopping at the square root of n? Why do we use an array of booleans? Allow me to explain how the sieve is working under the hood, and the mathematics behind _why_ it works:

At it's core, the sieve works because it utilizes the prime composite lemma. Plainly speaking, the sieve recognizes that all non-prime numbers are multiples of one or more prime numbers, or put another way all non-prime numbers are composed of prime numbers. Knowing this, the process of finding primes is done by finding and marking off (eliminating) all non-primes by looking at what primes we have found and eliminating their multiples. However, this fact on its own would simply make this a brute-force elimination sieve. Where the Sieve of Eratosthenes differs is that it also recognizes some other mathematical properties of the sieve that allow it to achieve its amazing time complexity. First, it recognizes that numbers before the square of the current prime will have already been eliminated by previous primes (there's a lemma expalining this but it's too long to include). Thus, for a given prime we should start at the square of the current prime for elimination (reduce redundancies). The second principle is that all multiples will have been eliminated by the time we've repeated this process as much as the square root of n times. This way we reduce two redundancies that are found in the brute force method.

## Pseudocode

Taken from the [Wikipedia: Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).
```
algorithm Sieve of Eratosthenes is
    input: an integer n > 1.
    output: all prime numbers from 2 through n.

    let A be an array of Boolean values, indexed by integers 2 to n, initially all set to true.
    
    for i = 2, 3, 4, ..., not exceeding √n do
        if A[i] is true
            for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n do
                set A[j] := false

    return all i such that A[i] is true.
```

---

Collaborative effort by [OpenGenus](https://github.com/opengenus)	

---
