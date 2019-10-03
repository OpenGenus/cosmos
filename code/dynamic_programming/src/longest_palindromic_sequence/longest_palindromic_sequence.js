/* Part of Cosmos by OpenGenus Foundation */

function longest_palindrome(str) {
  let longest = []; // A table to store results of subproblems

  // Strings of length 1 are palindrome of lentgh 1
  for (let i = 0; i < str.length; i++) {
    (longest[i] = longest[i] || [])[i] = 1;
  }

  for (let cl = 2; cl <= str.length; ++cl) {
    for (let i = 0; i < str.length - cl + 1; ++i) {
      let j = i + cl - 1;
      if (str[i] == str[j] && cl == 2) {
        longest[i][j] = 2;
      } else if (str[i] == str[j]) {
        longest[i][j] = longest[i + 1][j - 1] + 2;
      } else {
        longest[i][j] = Math.max(longest[i][j - 1], longest[i + 1][j]);
      }
    }
  }

  return longest[0][str.length - 1];
}

//test
[
  ["bbabcbcab", 7], // 7: babcbab | bacbcab
  ["abbaab", 4], // 4: abba | baab
  ["opengenus", 3] // 3: ene | ege | ngn | nen
].forEach(test => {
  console.assert(longest_palindrome(test[0]) == test[1]);
});
