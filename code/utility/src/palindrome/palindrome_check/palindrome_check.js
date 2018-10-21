const palindromeCheck = str => {
  // Make lowercase and remove non-alphabet characters
  const a = str.toLowerCase().replace(/[^a-z]/g, '');

  // Check if the string is the same as itself reversed
  return a == a.split('').reverse().join('');
}
