function russianPeasant(a, b) {
  let res = 0;
  while (b > 0) {
    if (b & 1) {
      res = res + a;
    }
    a = a << 1;
    b = b >>> 1;
  }
  return res;
}
console.log(russianPeasant(18, 1), russianPeasant(2, 4));
