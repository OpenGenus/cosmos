import math, itertools

# Tests whether the given integer is a prime number.
def is_prime_number(x):
    if x <= 1:
        return False
    elif x <= 3:
        return True
    elif x % 2 == 0:
        return False
    else:
        for i in range(3, int(math.sqrt(x)) + 1, 2):
            if x % i == 0:
                return False
        return True


def compute():
    # Note: b must be prime because when n = 0, the formula evaluates to just b.
    ans = max(
        ((a, b) for a in range(-999, 1000) for b in range(2, 1000) if is_prime(b)),
        key=count_consecutive_primes,
    )
    return str(ans[0] * ans[1])


def count_consecutive_primes(ab):
    a, b = ab
    for i in itertools.count():
        n = i * i + i * a + b
        if not is_prime(n):
            return i


isprimecache = list(map(is_prime_number, range(1000)))


def is_prime(n):
    if n < 0:
        return False
    elif n < len(isprimecache):
        return isprimecache[n]
    else:
        return is_prime_number(n)


if __name__ == "__main__":
    print(compute())
