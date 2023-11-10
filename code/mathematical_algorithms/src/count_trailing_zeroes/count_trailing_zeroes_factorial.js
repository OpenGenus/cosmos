const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question("Enter the number: ", num => {
  console.log(`Number of trailing zeroes in ${num}! : ` + trailingZeroes(num));
  rl.close();
});

function trailingZeroes(n) {
  var count = 0;
  for (var i = 5; n / i >= 1; i *= 5) {
    count += n / i;
  }
  return count;
}
