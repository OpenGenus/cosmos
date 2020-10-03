/* Part of Cosmos by OpenGenus Foundation */
/* Checker */
export function isPalindrome(str: string): boolean {
    const convertedString: Array<string> = [str];

    return convertedString.reverse().join("") === str
};

/* Tests */
isPalindrome("malayalam"); // should return true
isPalindrome("racecar"); // should return true
isPalindrome("opengenus"); // should return false
isPalindrome("alpha"); // should return false
isPalindrome("github"); // should return false
isPalindrome("level"); // should return true
isPalindrome("rotator"); // should return true