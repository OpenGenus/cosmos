from random import randint


def isPrime(n, k=10):
    if n <= 1:
        return False
    if n <= 3:
        return True
    for i in range(k):
        a = randint(2, n - 1)
        if pow(a, n - 1, n) != 1:
            return False
    return True


if __name__ == "__main__":
    if isPrime(103):
        print("Prime")
    else:
        print("Not prime")
