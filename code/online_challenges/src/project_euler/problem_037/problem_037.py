from math import sqrt

# Tests whether the given integer is a prime number.
def is_prime(x):
    if x <= 1:
        return False
    elif x <= 3:
        return True
    elif x % 2 == 0:
        return False
    else:
        for i in range(3, int(sqrt(x)) + 1, 2):
            if x % i == 0:
                return False
        return True


def compute():
    ans = 0
    found = 0
    n = 10
    while found < 11:
        if is_truncatable_prime(n):
            ans += n
            found += 1
        n += 1
    return str(ans)


def is_truncatable_prime(n):
    # Test if left-truncatable
    i = 10
    while i <= n:
        if not is_prime(n % i):
            return False
        i *= 10

        # Test if right-truncatable
    while n > 0:
        if not is_prime(n):
            return False
        n //= 10
    return True


if __name__ == "__main__":
    print(compute())
