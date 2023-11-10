# computes the sieve for the euler totient function
def ETF_sieve(N=1000000):
    sieve = [i for i in range(N)]

    for i in range(2, N, 1):
        if sieve[i] == i:  # this i would be a prime
            for j in range(i, N, i):
                sieve[j] *= 1 - 1 / i

    return sieve


# #tests
# sieve = ETF_sieve()
# print(sieve[1])
# print(sieve[2])
# print(sieve[3])
# print(sieve[10])
# print(sieve[20])
# print(sieve[200])
# print(sieve[2000])
