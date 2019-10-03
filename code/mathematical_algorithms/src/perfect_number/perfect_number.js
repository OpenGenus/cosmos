const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question("Enter a Number: ", number => {
  let hasPerfect = false;

  number = parseInt(number, 10);
  for (let i = 6; i < number; i++) {
    if (isPerfect(i)) {
      console.log(i + " is a perfect number.");
      hasPerfect = true;
    }
  }

  if (!hasPerfect) {
    console.log("No perfect numbers found.");
  }

  rl.close();
});

function isPerfect(number) {
  let sum = 0;
  for (let i = 1; i < number - 1; i++) {
    let rem = number % i;

    if (rem === 0) {
      sum += i;
    }
  }

  return sum === number;
}
