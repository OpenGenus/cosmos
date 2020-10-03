import random


def check(a, s, d, n):
    x = pow(a, d, n)
    if x == 1:
        return True
    for i in range(s - 1):
        if x == n - 1:
            return True
        x = pow(x, 2, n)
    return x == n - 1


def isPrime(n, k=10):
    if n == 2:
        return True
    if not n & 1:
        return False

    s = 0
    d = n - 1

    while d % 2 == 0:
        d >>= 1
        s += 1

    for i in range(k):
        a = random.randint(2, n - 1)
        if not check(a, s, d, n):
            return False
    return True
