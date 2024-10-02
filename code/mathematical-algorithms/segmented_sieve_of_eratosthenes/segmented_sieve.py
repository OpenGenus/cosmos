
# Part of Cosmos by Open Genus Foundation

import math

def prime_sieve(n):
    """Use the Sieve of Eratosthenes to list primes 0 to n."""
    primes = range(n+1)
    primes[1] = 0
    for i in range(4, n+1, 2):
        primes[i] = 0
    for x in range(3, int(math.sqrt(n))+1, 2):
        if primes[x]:
            for i in range(2*primes[x], n+1, primes[x]):
                primes[i] = 0
    return filter(None, primes)

def ranged_primes(x, y):
    """List primes between x and y."""
    primes = prime_sieve(int(math.sqrt(y)))
    return [n for n in range(x, y) if all(n % p for p in primes)]


print "Enter left range limit : "
x1=input()
print "Enter right range limit: "
x2=input()

print ranged_primes(x1,x2)



# Implementation contributed by Debajyoti Halder