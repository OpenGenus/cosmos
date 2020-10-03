/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * Method that returns the subsequenceLengthArray of the Longest Increasing Subsequence for the input array
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

  return subsequenceLengthArray;
}

/**
 * Method that returns the maximum bitonic subsequnce length for the input array
 * @param {array} inputArray
 */
function longestBitonicSubsequence(inputArray) {
  const incSubsequenceLengthArray = longestIncreasingSubsequence(inputArray);
  const decSubsequenceLengthArray = longestIncreasingSubsequence(
    inputArray.reverse()
  );

  /* Return the maximum value of incSubsequenceLengthArray[i] + decSubsequenceLengthArray[i] - 1*/
  let maxBitonicLength =
    incSubsequenceLengthArray[0] + decSubsequenceLengthArray[0] - 1;
  for (let i = 1; i < inputArray.length; i++) {
    if (
      incSubsequenceLengthArray[i] + decSubsequenceLengthArray[i] - 1 >
      maxBitonicLength
    ) {
      maxBitonicLength =
        incSubsequenceLengthArray[i] + decSubsequenceLengthArray[i] - 1;
    }
  }
  return maxBitonicLength;
}

console.log(
  `Longest Bitonic Subsequence Length - ${longestBitonicSubsequence([
    0,
    8,
    4,
    12,
    2,
    10,
    6,
    14,
    1,
    9,
    5,
    13,
    3,
    11,
    7,
    15
  ])}`
);
