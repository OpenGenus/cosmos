import sys


def fibonacci(n):
    if n < 2:
        return n
    return fibonacci(n - 2) + fibonacci(n - 1)


def fibonacci_memoized(n):
    cache = {0: 0, 1: 1}

    def fib(n):
        if n not in cache:
            cache[n] = fib(n - 2) + fib(n - 1)
        return cache[n]

    return fib(n)


x = int(sys.argv[1])
print(fibonacci_memoized(x))
