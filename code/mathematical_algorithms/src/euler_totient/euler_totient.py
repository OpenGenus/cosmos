# Part of Cosmos by OpenGenus Foundation
import math


def phi(n):
    result = n
    for p in range(2, int(math.sqrt(n) + 1)):
        if n % p == 0:
            while n % p == 0:
                n = int(n / p)
            result = result - int(result / p)

    if n > 1:
        result = result - int(result / n)
    return result


n = int(input())
for i in range(1, n + 1):
    ans = phi(i)
    print("phi(" + str(i) + ") = " + str(ans))
