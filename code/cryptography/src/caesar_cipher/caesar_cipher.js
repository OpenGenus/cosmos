/* Part of Cosmos by OpenGenus Foundation */
// Caesar Cipher in javascript

//Use the 'Ref' string to set the range of characters that can be encrypted. Characters not in 'Ref' will not be encoded
const Ref = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// text = the string to be encrypted/decrypted
// shift = the amount of shift for encryption/decryption

function caesar_cipher(text, shift) {
  shift %= Ref.length;
  if (shift < 0) {
    shift += Ref.length;
  }

  return text
    .split("")
    .map(cv => {
      let loc = Ref.indexOf(cv);
      return loc !== -1
        ? Ref.charAt(
            loc + shift < Ref.length ? loc + shift : loc + shift - Ref.length
          )
        : cv;
    })
    .join("");
}
/*
 -Sample use:
 let encrypted = caesar_cipher( "Hello World", 10 );
 -Then to decrypt
 let decrypted = caesar_cipher( encrypted, -10 );
 */
