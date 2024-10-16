function gcd(a, b) {
  return b === 0 ? a : gcd(b, a % b);
}

function lcm(a, b) {
  return b === 0 ? 0 : (a * b) / gcd(a, b);
}

// GCD
console.log(gcd(15, 2)); // 1
console.log(gcd(144, 24)); // 24

// LCM
console.log(lcm(12, 3)); // 12
console.log(lcm(27, 13)); // 351
