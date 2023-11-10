# Sieve of Eratosthenes

Learn at [**OpenGenus IQ**](https://iq.opengenus.org/the-sieve-of-eratosthenes/)

Sieve of Eratosthenes is used to find prime numbers up to some predefined integer n. For sure, we can just test all the numbers in range from 2 to n for primality using some approach, but it is quite inefficient. Sieve of Eratosthenes is a simple algorithm to find prime numbers. Though, there are better algorithms exist today, sieve of Eratosthenes is a great example of the sieve approach.

<b>Algorithm</b>

First of all algorithm requires a bit array isComposite to store n - 1 numbers: isComposite[2 .. n]. Initially the array contains zeros in all cells. During algorithm's work, numbers, which can be represented as k * p, where k ≥ 2, p is prime, are marked as composite numbers by writing 1 in a corresponding cell. Algorithm consists of two nested loops: outer, seeking for unmarked numbers (primes), and inner, marking primes' multiples as composites.
<ul type="disc">

<li>For all numbers m: 2 .. n, if m is unmarked:</li>
<ul type="circle">
  <li> add m to primes list;</li>

<li>  mark all it's multiples, lesser or equal, than n (k * m ≤ n, k ≥ 2);</li>
</ul>
<li>otherwise, if m is marked, then it is a composite number.</li>
</ul>

<b>Modification</b>

Let's notice, that algorithm can start marking multiples beginning from square of a found unmarked number. Indeed,

For m = 2, algorithm marks

	2 * 2   3 * 2   4 * 2   5 * 2   6 * 2   7 * 2   ...
For m = 3,

	2 * 3
were already marked on m = 2 step.

For m = 5,

	2 * 5   3 * 5   4 * 5 (= 10 * 2)
were already marked on m = 2 and m = 3 steps.

Strong proof is omitted, but you can easily prove it on your own. Modified algorithm is as following:
<ul type="disc">
  <li>For all numbers m: 2 .. √n, if m is unmarked:</li>
<ul type="circle">
<li>add m to primes list;</li>

<li>mark all it's multiples, starting from square, lesser or equal than n (k * m ≤ n, k ≥ m);</li>
</ul>
<li>otherwise, if m is marked, then it is a composite number;</li>

<li>check all numbers in range √n .. n. All found unmarked numbers are primes, add them to list.</li>
</ul>

Collaborative effort by [OpenGenus](https://github.com/opengenus)	
