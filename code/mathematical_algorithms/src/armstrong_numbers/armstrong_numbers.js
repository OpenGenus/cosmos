const readline = require("readline");

const ioInterface = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

ioInterface.question("Enter a three digit integer: ", answer => {
  var armstrong = answer
    .split("")
    .map(num => parseInt(num) ** 3)
    .reduce((elem, sum) => elem + sum);
  console.log(
    `${answer} is ${
      armstrong == parseInt(answer) ? "" : "not "
    }an Armstrong number.`
  );
  ioInterface.close();
});
