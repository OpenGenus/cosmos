function reverse_number(value) {
  let reversed = String(value)
    .split("")
    .reverse()
    .join("");
  return Number(reversed);
}

console.log(reverse_number(123456789)); // 987654321
console.log(reverse_number(12.34)); // 43.21
