const Readline = require("readline");

const rl = Readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const replace0with5 = function replace0with5(number) {
  return number.replace(new RegExp("0", "g"), 5);
};

rl.question("Enter a number: ", number => {
  console.log(replace0with5(number));
  rl.close();
});
