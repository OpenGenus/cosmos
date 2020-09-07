// Part of Cosmos by OpenGenus Foundation
// Find of average of numbers in an array
// Contributed by: Michele Riva (micheleriva)

export const average = numbers => {
  const sum = numbers.reduce((a, b) => a + b, 0);
  return sum / numbers.length;
};

/* Test */
const n = [10, 20, 30, 40];
average(n); // => 25
