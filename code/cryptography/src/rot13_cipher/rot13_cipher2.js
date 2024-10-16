/**
 * Run rotation cipher on a string
 * @param {string} text - Text to encrypt
 * @param {number} n - Amount to shift by
 * @return {string} Encoded string
 */
const rotN = function rot(text, n) {
  let output = "";

  // Loop through input
  for (let char of text) {
    // Get ASCII code
    let ascii = char.charCodeAt(0);
    // Check if character is not a letter
    if (ascii < 65 || ascii > 122) {
      output += String(char);
    } else {
      // Subtract 'A' if uppercase, 'a' if lowercase
      let sub = ascii >= 65 && ascii <= 90 ? "A" : "a";
      // Convert to alphabet index starting from zero (0 - 25)
      ascii -= sub.charCodeAt(0);
      // Shift
      ascii += n;
      // Wrap around
      ascii = ascii % 26;
      // Convert back to ASCII code and add to output
      output += String.fromCharCode(ascii + sub.charCodeAt(0));
    }
  }

  return output;
};

// Examples
console.log(rotN("Hello, world!", 13)); // Outputs "Uryyb, jbeyq!"
