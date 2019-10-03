function greatestDigit(num) {
  return String(num)
    .split("")
    .reduce((a, b) => Math.max(a, b));
}

console.log(greatestDigit(123)); // 3
console.log(greatestDigit(321)); // 3
console.log(greatestDigit(12903)); // 9
