/* Part of Cosmos by OpenGenus Foundation */
/* Checker */
const alphabet = [..."abcdefghijklmnopqrstuvwxyz"];

const checkPangram = str =>
  alphabet.every(char => str.toLowerCase().includes(char));

/* Test */
checkPangram("Totally not a panagram"); // should return false
checkPangram("Still not a panagram"); // should return false
checkPangram("The quick brown fox jumps over a lazy dog"); // should return true
checkPangram("Pack my box with five dozen liquor jugs"); // should return true
checkPangram("The five boxing wizards jump quickly"); // should return true
