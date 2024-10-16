import sys

# Part of Cosmos by OpenGenus Foundation
def sieve_erato(n):
    loops = 0
    numbers = set(range(2, n))
    for i in range(2, int(n ** 0.5) + 1):
        for j in range(i * 2, n, i):
            numbers.discard(j)
            loops += 1
    return sorted(numbers), loops


try:
    primes = sieve_erato(int(input().rstrip()))
except:
    sys.exit()

print(primes[0])
print("\nComputations {}".format(primes[1]))
