from math import sqrt

# Returns a list of True and False indicating whether each number is prime.
# For 0 <= i <= n, result[i] is True if i is a prime number, False otherwise.
def list_primality(n):
    # Sieve of Eratosthenes
    result = [True] * (n + 1)
    result[0] = result[1] = False
    for i in range(int(sqrt(n)) + 1):
        if result[i]:
            for j in range(i * i, len(result), i):
                result[j] = False
    return result


def compute():
    isprime = list_primality(1000000)
    for i in range(len(isprime)):
        if not isprime[i]:
            continue

        n = [int(c) for c in str(i)]
        for mask in range(1 << len(n)):
            digits = do_mask(n, mask)
            count = 0
            for j in range(10):
                if digits[0] != 0 and isprime[to_number(digits)]:
                    count += 1
                digits = add_mask(digits, mask)

            if count == 8:
                digits = do_mask(n, mask)
                for j in range(10):
                    if digits[0] != 0 and isprime[to_number(digits)]:
                        return str(to_number(digits))
                    digits = add_mask(digits, mask)
    raise AssertionError("Not found")


def do_mask(digits, mask):
    return [d * ((~mask >> i) & 1) for (i, d) in enumerate(digits)]


def add_mask(digits, mask):
    return [d + ((mask >> i) & 1) for (i, d) in enumerate(digits)]


def to_number(digits):
    result = 0
    for d in digits:
        result = result * 10 + d
    return result


if __name__ == "__main__":
    print(compute())
