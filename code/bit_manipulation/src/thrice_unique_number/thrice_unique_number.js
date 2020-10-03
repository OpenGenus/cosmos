// Part of Cosmos by OpenGenus Foundation

let numbers = [
  1,
  1,
  1,
  2,
  2,
  2,
  3,
  3,
  3,
  4,
  5,
  5,
  5,
  6,
  6,
  6,
  7,
  7,
  7,
  8,
  8,
  8,
  9,
  9,
  9
];
let counter = {};

for (var index = 0; index < numbers.length; index++) {
  let current = counter[numbers[index]];

  if (current === undefined) {
    counter[numbers[index]] = 1;
  } else {
    counter[numbers[index]] = current + 1;
  }
}

for (let num in counter) {
  let count = counter[num];

  if (count === 1) {
    console.log(`Unique number is ${num}`);
  }
}
