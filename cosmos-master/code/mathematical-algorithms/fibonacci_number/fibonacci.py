import sys

def fibonacci(n):
  if n < 2:
    return n
  return fibonacci(n-2) + fibonacci(n-1)

def fibonacci_memoized(n):
  cache = {0: 0, 1: 1}
  if n in cache:
    return cache[n]
  cache[n] = fibonacci_memoized(n-2) + fibonacci_memoized(n-1)
  return cache[n]

x = int(sys.argv[1])
print fibonacci_memoized(x)