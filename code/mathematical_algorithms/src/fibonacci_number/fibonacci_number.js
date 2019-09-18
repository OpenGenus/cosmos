function fibonacci(n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 2) + fibonacci(n - 1);
  }
}

function memoizedFibonacci(n, cache = { 0: 0, 1: 1 }) {
  if (!(n in cache)) {
    cache[n] =
      memoizedFibonacci(n - 2, cache) + memoizedFibonacci(n - 1, cache);
  }
  return cache[n];
}

fibonacci(18); // 2584
memoizedFibonacci(20); // 6765
