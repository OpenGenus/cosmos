# Pollard-Rho-Brent Integer factorisation
# Complexity: O(n^(1/4) * log2(n))
# Output is list of primes factors & exponents.
# Example, N = 180 gives : [[2, 2], [3, 2], [5, 1]]

import random
from queue import Queue


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def expo(a, b):
    x, y = 1, a
    while b > 0:
        if b & 1:
            x = x * y
        y = y * y
        b >>= 1
    return x


primes = [0] * 100000


def sieve():
    primes[1] = 1
    primes[2] = 2
    j = 4
    while j < 100000:
        primes[j] = 2
        j += 2
    j = 3
    while j < 100000:
        if primes[j] == 0:
            primes[j] = j
            i = j * j
            k = j << 1
            while i < 100000:
                primes[i] = j
                i += k
        j += 2


# Checks if p is prime or not.
def rabin_miller(p):
    if p < 100000:
        # Precomputation make checking for small numbers O(1).
        return primes[p] == p
    if p % 2 == 0:
        return False
    s = p - 1
    while s % 2 == 0:
        s >>= 1
    for i in range(5):
        a = random.randrange(p - 1) + 1
        temp = s
        mod = pow(a, temp, p)
        while temp != p - 1 and mod != 1 and mod != p - 1:
            mod = (mod * mod) % p
            temp = temp * 2
        if mod != p - 1 and temp % 2 == 0:
            return False
    return True


# Returns a prime factor of N.
def brent(N):
    if N % 2 == 0:
        return 2
    if N < 100000:
        return primes[N]
    y, c, m = (
        random.randint(1, N - 1),
        random.randint(1, N - 1),
        random.randint(1, N - 1),
    )
    g, r, q = 1, 1, 1
    while g == 1:
        x = y
        for i in range(r):
            y = ((y * y) % N + c) % N
        k = 0
        while k < r and g == 1:
            ys = y
            for i in range(min(m, r - k)):
                y = ((y * y) % N + c) % N
                q = q * (abs(x - y)) % N
            g = gcd(q, N)
            k = k + m
        r = r * 2
    if g == N:
        while True:
            ys = ((ys * ys) % N + c) % N
            g = gcd(abs(x - ys), N)
            if g > 1:
                break
    return g


def factorise(n):
    if n == 1:
        return []
    Q_1 = Queue()
    Q_2 = []
    Q_1.put(n)
    while not Q_1.empty():
        l = Q_1.get()
        if rabin_miller(l):
            Q_2.append(l)
            continue
        d = brent(l)
        if d == l:
            Q_1.put(l)
        else:
            Q_1.put(d)
            Q_1.put(l // d)
    return Q_2


if __name__ == "__main__":
    sieve()
    t = int(input())  # Denotes number of testcases.
    for _ in range(t):
        n = int(input())
        L = factorise(n)
        L.sort()
        i = 0
        factors = []
        while i < len(L):
            cnt = L.count(L[i])
            factors.append([L[i], cnt])
            i += cnt
        print(factors)
