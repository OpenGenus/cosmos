function bitwiseRecursiveAddition(n, m) {
  if (m == 0) return n;

  let carry = n & m;
  return bitwiseRecursiveAddition(n ^ m, carry << 1);
}

function bitwiseIterativeAddition(n, m) {
  while (m != 0) {
    let carry = n & m;
    n ^= m;
    m = carry << 1;
  }
  return n;
}

console.log(bitwiseIterativeAddition(10, 20));
console.log(bitwiseRecursiveAddition(30, 20));
