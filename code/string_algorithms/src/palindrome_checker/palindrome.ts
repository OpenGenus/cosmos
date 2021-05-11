/* Part of Cosmos by OpenGenus Foundation */
/* Checker */
export function isPalindrome(str: string): boolean {
    return str.split("").reverse().join("") === str;
};

/* Tests */
console.log(isPalindrome("malayalam")); // should return true
console.log(isPalindrome("racecar")); // should return true
console.log(isPalindrome("opengenus")); // should return false
console.log(isPalindrome("alpha")); // should return false
console.log(isPalindrome("github")); // should return false
console.log(isPalindrome("level")); // should return true
console.log(isPalindrome("rotator")); // should return true
