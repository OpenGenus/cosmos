// Author: Amit Kr. Singh
// Github: @amitsin6h
// Social: @amitsin6h
// OpenGenus Contributor

// Contributor: Igor Antun
// Github: @IgorAntun

/* Checker */
const checkPalindrome = str => [...str].reverse().join("") === str;

/* Tests */
checkPalindrome("malayalam"); // should return true
checkPalindrome("racecar"); // should return true
checkPalindrome("opengenus"); // should return false
checkPalindrome("alpha"); // should return false
checkPalindrome("github"); // should return false
checkPalindrome("level"); // should return true
checkPalindrome("rotator"); // should return true
