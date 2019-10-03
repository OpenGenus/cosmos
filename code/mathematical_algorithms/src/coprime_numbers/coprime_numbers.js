const Readline = require("readline");

const rl = Readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function gcd(a, b) {
  while (b != 0) {
    let temp = a % b;

    a = b;
    b = temp;
  }

  return a;
}

function coPrime(a, b) {
  if (a > b) {
    return gcd(a, b) == 1;
  } else {
    return gcd(b, a) == 1;
  }
}

rl.question(
  "Enter two values to find for relative prime or co prime: ",
  numbers => {
    let [a, b] = numbers.split(" ").filter(function(e) {
      return parseInt(e, 10);
    });

    console.log(coPrime(a, b));

    rl.close();
  }
);
