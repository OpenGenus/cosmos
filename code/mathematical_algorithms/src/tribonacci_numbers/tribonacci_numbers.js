function tribonacci(n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  }
  return tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
}

tribonacci(15); //1705
