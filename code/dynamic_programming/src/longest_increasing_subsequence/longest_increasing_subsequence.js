/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * Method that returns the length of the Longest Increasing Subsequence for the input array
 * @param {array} inputArray
 */
function longestIncreasingSubsequence(inputArray) {
  // Get the length of the array
  let arrLength = inputArray.length;
  let i, j;

  let subsequenceLengthArray = [];

  for (i = 0; i < arrLength; i++) {
    subsequenceLengthArray[i] = 1;
  }

  for (i = 1; i < arrLength; i++) {
    for (j = 0; j < i; j++)
      if (
        inputArray[j] < inputArray[i] &&
        subsequenceLengthArray[j] + 1 > subsequenceLengthArray[i]
      ) {
        subsequenceLengthArray[i] = subsequenceLengthArray[j] + 1;
      }
  }

  return Math.max(...subsequenceLengthArray);
}

console.log(
  `Longest Increasing Subsequence Length - ${longestIncreasingSubsequence([
    10,
    22,
    9,
    33,
    21,
    50,
    41,
    60,
    80
  ])}`
);
