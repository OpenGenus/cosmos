/* Part of Cosmos by OpenGenus Foundation */
//Sum of Digits - Add all digits in a number

// returns the sum of digits or -1 on invalid input

//Val must be a positive whole number

function sumOfDigits(val) {
  if (typeof val !== "number" || val !== Math.ceil(val) || val < 0) {
    return -1;
  }
  let sum = 0;
  while (Math.floor(val) > 0) {
    sum += Math.floor(val % 10);
    val /= 10;
  }
  return sum;
}

// sumOfDigits_S accepts numbers as type 'number' or string

function sumOfDigits_S(val) {
  if (
    (typeof val !== "number" && typeof val !== "string") ||
    +val !== Math.ceil(+val) ||
    +val < 0
  ) {
    return -1;
  }
  return val
    .toString()
    .split("")
    .reduce((t, cv) => {
      return t + +cv;
    }, 0);
}
