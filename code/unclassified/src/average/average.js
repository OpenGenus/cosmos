/* Part of Cosmos by OpenGenus Foundation */

// finds the average of an array of numbers.
//Using map function
function getAverage(numbers) {
  var sum = 0;
  numbers.map(function(number) {
    sum += number;
  });
  return sum / numbers.length;
}

nums = [10, 20, 30, 40, 50];
console.log(getAverage(nums));
