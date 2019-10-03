# Part of Cosmos by OpenGenus Foundation
from math import sqrt, ceil


def atkin_sieve(n):

    # Include 2,3,5 in initial results
    if n >= 5:
        result = [2, 3, 5]
    elif n >= 3 and n < 5:
        result = [2, 3]
    elif n == 2:
        result = [2]
    else:
        result = []

    # Initialize sieve; all integers marked as non-prime
    sieve = [0] * n
    root = ceil(sqrt(n))

    # Flip entry in sieve based on n mod 60=r:
    # Per solution to n = 4*x^2 + y^2 if r in [1,13,17,29,37,41,49,53]
    # Per solution to n = 3*x^2 + y^2 if r in [7,19,31,43]
    # Per solution to n = 3*x^2 - y^2 when y<x if r in [11,23,47,59]
    xy = [(x, y) for x in range(1, root + 1) for y in range(1, root + 1)]
    for (x, y) in xy:
        i = 4 * x * x + y * y
        if (i <= n) and (i % 60 in [1, 13, 17, 29, 37, 41, 49, 53]):
            sieve[i - 1] ^= 1
        i = 3 * x * x + y * y
        if (i <= n) and (i % 60 in [7, 19, 31, 43]):
            sieve[i - 1] ^= 1
        if x > y:
            i = 3 * x * x - y * y
            if (i <= n) and (i % 60 in [11, 23, 47, 59]):
                sieve[i - 1] ^= 1

    # Remove multiples of the squares of remaining integers
    for i in range(2, root):
        j = i * i
        while j < n:
            sieve[j - 1] = 0
            j += i * i

    # Add sieved results to the result list
    result += [i for (i, n) in list(zip(range(1, n + 1), sieve)) if n == 1]

    return result
