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


isprime = list_primality(999999)


def compute():
    ans = 0
    for i in xrange(len(isprime)):
        if is_circular_prime(i):
            ans += 1
    return str(ans)


def is_circular_prime(n):
    s = str(n)
    for i in xrange(len(s)):
        if not isprime[int(s[i:] + s[:i])]:
            return False
    return True


if __name__ == "__main__":
    print(compute())
