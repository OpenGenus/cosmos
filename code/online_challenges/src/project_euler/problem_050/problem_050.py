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


# Returns all the prime numbers less than or equal to n, in ascending order.
# For example: listPrimes(97) = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, ..., 83, 89, 97].
def list_primes(n):
    return [i for (i, isprime) in enumerate(list_primality(n)) if isprime]


def compute():
    ans = 0
    isprime = list_primality(999999)
    primes = list_primes(999999)
    consecutive = 0
    for i in range(len(primes)):
        sum = primes[i]
        consec = 1
        for j in range(i + 1, len(primes)):
            sum += primes[j]
            consec += 1
            if sum >= len(isprime):
                break
            if isprime[sum] and consec > consecutive:
                ans = sum
                consecutive = consec
    return str(ans)


if __name__ == "__main__":
    print(compute())
