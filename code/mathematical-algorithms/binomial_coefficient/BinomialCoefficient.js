function binomialCoeffiecient(n, k) {
  let a = Array(n + 1);
  a[0] = 1;
  a.fill(0, 1, n + 1);
  for (let i = 0; i < n; ++i) {
    for (let j = i + 1; j > 0; --j) {
      a[j] = a[j - 1] + a[j];
    }
  }
  return a[k];
}
