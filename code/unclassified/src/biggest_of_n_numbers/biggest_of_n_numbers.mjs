/**
 * 
 * @param {number[]} numbers List of numbers
 * @returns Biggest number in given list
 */
const max = numbers =>
  numbers.reduce((max, current) => (current > max ? current : max), numbers[0]);

// Tests  
console.log(max([4, 2, 1, 7]));
console.log(max([10, 3, 8, 7]));
