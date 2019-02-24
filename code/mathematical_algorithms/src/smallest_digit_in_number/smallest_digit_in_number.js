const smallest_digit_in_number = input => {
  if (typeof input !== "number") {
    console.error("Please enter a number.");
    return;
  }

  const numbers = [];

  let number = input;

  while (number > 0) {
    const n = number % 10;

    numbers.push(n);

    number = Math.floor(number / 10);
  }

  numbers.sort();

  return numbers[0];
};

console.log(smallest_digit_in_number(243245));
