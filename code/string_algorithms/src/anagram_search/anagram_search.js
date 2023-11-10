// Part of Cosmos by OpenGenus Foundation

// Checks if two strings are anagrams of each other, ignoring any whitespace.
//
// Remove whitespaces in both strings.
// Make all characters in both strings lowercase.
// Use .reduce() to create a hash table for each word containing the counts for each letter.
// Compare both hash tables to see if one contains any letters not contained in the other table.
// Check to ensure every unique character is used in both strings the same number of times.

var removeWhiteSpace = str => {
  var splitStr = str.split("");
  var letters = [];
  for (var i = 0; i < splitStr.length; i++) {
    if (splitStr[i] !== " ") {
      letters.push(splitStr[i]);
    }
  }
  var strNoSpaces = letters.join("");
  return strNoSpaces;
};

var charCountTable = str => {
  var letters = str.split("");
  var counts = letters.reduce((instances, a) => {
    if (a in instances) {
      instances[a]++;
    } else {
      instances[a] = 1;
    }
    return instances;
  }, {});
  return counts;
};

var checkIfAnagrams = (str1, str2) => {
  str1 = removeWhiteSpace(str1.toLowerCase());
  str2 = removeWhiteSpace(str2.toLowerCase());

  var str1LetterCount = charCountTable(str1);
  var str2LetterCount = charCountTable(str2);

  var str1LetterKeys = Object.keys(str1LetterCount);
  var str2LetterKeys = Object.keys(str2LetterCount);

  if (str1LetterKeys.length !== str2LetterKeys.length) {
    return false;
  } else {
    for (var i = 0; i < str1LetterKeys.length; i++) {
      if (
        str1LetterCount[str1LetterKeys[i]] ===
        str2LetterCount[str1LetterKeys[i]]
      ) {
        continue;
      } else {
        return false;
      }
    }
    return true;
  }
};

checkIfAnagrams("bob", " "); // => false
checkIfAnagrams("aabb", "baba"); // => true
checkIfAnagrams("aab", " aa b"); // => true
checkIfAnagrams("bob", "ob oo"); // => false
