/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * Method which returns the Minimum Cuts to perform Palindrome Partioning
 * @param {string} inputString
 */
function palindromePartioning(inputString) {
  // Get the length of the string
  let strLength = inputString.length;
  let minCuts = 0;
  let i, L, j;

  /* 
    Create two arrays to build the solution in bottom up manner
    cutMatrix = Minimum number of cuts needed for palindrome partitioning of substring inputString[0..i]
    palMatrix = true if substring inputString[i..j] is palindrome, else false
  */
  let palMatrix = [];
  let cutMatrix = [];

  // for single letter palindromes set them true (since they palindrome on there own)
  for (i = 0; i < strLength; i++) {
    // lazy initialize the element of 2d array
    if (!palMatrix[i]) palMatrix[i] = [];
    palMatrix[i][i] = true;
  }

  /* L is substring length. Build the solution in bottom up manner by
       considering all substrings of length starting from 2 to n. */
  for (L = 2; L <= strLength; L++) {
    // For substring of length L, set different possible starting indexes
    for (i = 0; i < strLength - L + 1; i++) {
      j = i + L - 1; // Set ending index

      // If L is 2, then we just need to compare two characters. Else
      // need to check two corner characters and value of palMatrix[i+1][j-1]
      if (L == 2) {
        if (!palMatrix[i]) palMatrix[i] = [];
        palMatrix[i][j] = inputString[i] == inputString[j];
      } else {
        if (!palMatrix[i]) palMatrix[i] = [];
        palMatrix[i][j] =
          inputString[i] == inputString[j] && palMatrix[i + 1][j - 1];
      }
    }
  }

  for (i = 0; i < strLength; i++) {
    if (palMatrix[0][i] == true) cutMatrix[i] = 0;
    else {
      cutMatrix[i] = strLength;
      for (j = 0; j < i; j++) {
        if (palMatrix[j + 1][i] == true && 1 + cutMatrix[j] < cutMatrix[i])
          cutMatrix[i] = 1 + cutMatrix[j];
      }
    }
  }
  // Return the min cut value for complete string.
  return cutMatrix[strLength - 1];
}

console.log(
  `Minimum Cuts to perform Palindrome Partioning - ${palindromePartioning(
    "hallelujah"
  )}`
);
