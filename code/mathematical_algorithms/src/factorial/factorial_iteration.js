function factorial(n) {
  let ans = 1;
  for (let i = 1; i <= n; i += 1) {
    ans = ans * i;
  }
  return ans;
}

const num = 3;
console.log(factorial(num));
