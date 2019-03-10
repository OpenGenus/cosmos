import math

# Returns a list of True and False indicating whether each number is prime.
# For 0 <= i <= n, result[i] is True if i is a prime number, False otherwise.
def list_primality(n):
    # Sieve of Eratosthenes
    result = [True] * (n + 1)
    result[0] = result[1] = False
    for i in range(int(math.sqrt(n)) + 1):
        if result[i]:
            for j in range(i * i, len(result), i):
                result[j] = False
    return result


def compute():
    LIMIT = 10000
    isprime = list_primality(LIMIT - 1)
    for base in range(1000, LIMIT):
        if isprime[base]:
            for step in range(1, LIMIT):
                a = base + step
                b = a + step
                if (
                    a < LIMIT
                    and isprime[a]
                    and has_same_digits(a, base)
                    and b < LIMIT
                    and isprime[b]
                    and has_same_digits(b, base)
                    and (base != 1487 or a != 4817)
                ):
                    return str(base) + str(a) + str(b)
    raise RuntimeError("Not found")


def has_same_digits(x, y):
    return sorted(str(x)) == sorted(str(y))


if __name__ == "__main__":
    print(compute())
