function binomial_Coeff(n, k) {
  let res = 1;

  if (k > n - k) {
    k = n - k;
  }

  for (let i = 0; i < k; i++) {
    res *= n - i;
    res /= i + 1;
  }

  return res;
}
function catalan(n) {
  const c = binomial_Coeff(2 * n, n);
  return c / (n + 1);
}

for (let j = 0; j < 10; j++) {
  console.log(catalan(j));
}
