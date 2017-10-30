#include <stdio.h>
#include <stdlib.h>
/* Part of Cosmos by OpenGenus Foundation */
int sieve_of_eratosthenes(int **primes, const int max) {
	// Allocate memory
	int *isPrime = (int *)malloc(sizeof(int) * (max + 1));
	int i;
	// Assume all numbers to be prime initially
	for(i = 0; i <= max; ++i)
		isPrime[i] = 1;
	// 0 and 1 are not prime
	isPrime[0] = 0;
	isPrime[1] = 0;
	// Maintain a count of primes as we encounter them
	int count = 0;
	// We need a count of all primes as we move
	// This means we cannot iterate to root(max)
	for(i = 2; i <= max; ++i)
	{
		if(isPrime[i] == 1)
		{
			++count;
			int j;
			// Set all multiples of i as not prime
			for(j = 2 * i; j <= max; j += i)
				isPrime[j] = 0;
		}
	}
	*primes = (int *)malloc(sizeof(int) * count);
	int j = 0;
	for(i = 0; i <= max; ++i)
	{
		if(isPrime[i] == 1)
		{
			(*primes)[j++] = i;
		}

	}
	return count;
}

int main() {
	int n = 100, i;
	int *primes = NULL;
	// Find primes up to n
	int size = sieve_of_eratosthenes(&primes, n);
	printf("Primes up to %d are:\n", n);
	for(i = 0; i < size; ++i)
	{
		printf("%d\n", primes[i]);
	}
	return 0;
}
