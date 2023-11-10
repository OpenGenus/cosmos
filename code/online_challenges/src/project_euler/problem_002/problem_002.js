let sum = 0;
let num1 = 0;
let num2 = 0;
let current = 1;
while (current < 4000000) {
  sum += current % 2 === 0 ? current : 0;

  num2 = num1;
  num1 = current;
  current = num2 + num1;
}
console.log(sum);
