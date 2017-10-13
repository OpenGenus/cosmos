// Part of Cosmos by OpenGenus Foundation

// Checks if two strings are anagrams of each other, ignoring any whitespace.
//
// Remove whitespaces in both strings.
// Make all characters in both strings lowercase.
// Use .reduce() to create a hash table for each word containing the counts for each letter.
// Compare both hash tables to see if one contains any letters not contained in the other table.
//
// Check to ensure every unique character is used in both strings the same number of times.

removeWhiteSpace(str) => {
  return ''.join(str.split(''));
};

charCountTable(str) => {
  var letters = str.split('');
  var counts = letters.reduce((instances,a) => {
    if(a in instances) {
      instances[a]++;
    } else {
      instances[a] = 1;
    }
    return instances;
  }, {});
  return counts;
};

checkIfAnagrams(str1,str2) => {

};
