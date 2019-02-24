/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * method which returns the maximum total value in the knapsack
 * @param {array} valueArray
 * @param {array} weightArray
 * @param {integer} maximumWeight
 */
function knapsack(valueArray, weightArray, maximumWeight) {
  let n = weightArray.length;
  let matrix = [];

  // lazy initialize the element of 2d array
  if (!matrix[0]) matrix[0] = [];

  // if the knapsack's capacity is 0 - Set all columns at row 0 to be 0
  for (let inc = 0; inc <= maximumWeight; inc++) {
    matrix[0][inc] = 0;
  }

  for (let i = 1; i < n + 1; i++) {
    // check all possible maxWeight values from 1 to W
    for (let j = 1; j < maximumWeight + 1; j++) {
      // lazy initialize the element of 2d array
      if (!matrix[j]) matrix[j] = [];

      // if current item weighs < j then we have two options,
      if (weightArray[i - 1] <= j) {
        // Given a weight, check if the value of the current item + value of the item that we could afford with the remaining weight
        // is greater than the value without the current item itself
        matrix[i][j] = Math.max(
          matrix[i - 1][j],
          valueArray[i - 1] + matrix[i - 1][j - weightArray[i - 1]]
        );
      } else {
        // If the current item's weight is more than the running weight, just carry forward the value without the current item
        matrix[i][j] = matrix[i - 1][j];
      }
    }
  }

  return matrix[n][maximumWeight];
}

console.log(
  "Result - " + knapsack([12, 1000, 30, 10, 1000], [19, 120, 20, 1, 120], 40)
);
