/*

// unclassified | palindrome | palindrome check | palindrome check | JAVASCRIPT
// Part of Cosmos by OpenGenus Foundation

*/


function isPalindrome(str) {
  return [...str].reverse().join("") == str;
}

console.log(isPalindrome("lol"));
console.log(isPalindrome("nitin"));
console.log(isPalindrome("terabyte"));
console.log(isPalindrome("tbhaxor"));

// Output
// true
// true
// false
// false
