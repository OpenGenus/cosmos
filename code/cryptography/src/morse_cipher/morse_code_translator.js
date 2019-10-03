// Javascript program to implement morse code translator

/*
 * VARIABLE KEY
 * 'cipher' -> 'stores the morse translated form of the english string'
 *  'decipher' -> 'stores the english translated form of the morse string'
 * 'citext' -> 'stores morse code of a single character'
 * 'i' -> 'keeps count of the spaces between morse characters'
 * 'message' -> 'stores the string to be encoded or decoded'
 */

// Object representing the morse code chart
const MORSE_CODES = {
  A: ".-",
  B: "-...",
  C: "-.-.",
  D: "-..",
  E: ".",
  F: "..-.",
  G: "--.",
  H: "....",
  I: "..",
  J: ".---",
  K: "-.-",
  L: ".-..",
  M: "--",
  N: "-.",
  O: "---",
  P: ".--.",
  Q: "--.-",
  R: ".-.",
  S: "...",
  T: "-",
  U: "..-",
  V: "...-",
  W: ".--",
  X: "-..-",
  Y: "-.--",
  Z: "--..",
  "1": ".----",
  "2": "..---",
  "3": "...--",
  "4": "....-",
  "5": ".....",
  "6": "-....",
  "7": "--...",
  "8": "---..",
  "9": "----.",
  "0": "-----",
  ",": "--..--",
  ".": ".-.-.-",
  "?": "..--..",
  "/": "-..-.",
  "-": "-....-",
  "(": "-.--.",
  ")": "-.--.-"
};

// Array of values from above
const CODE_VALS = Object.keys(MORSE_CODES).map(key => MORSE_CODES[key]);

// Function to encrypt the string according to the morse code chart
function encrypt(message) {
  var cipher = "";
  message.split("").forEach(letter => {
    if (letter !== " ") {
      // looks up the dictionary and adds the correspponding morse code
      // along with a space to separate morse codes for different characters
      cipher += MORSE_CODES[letter] + " ";
    } else {
      // 1 space indicates different characters & 2 indicates different words
      cipher += " ";
    }
  });

  return cipher;
}

// Function to decrypt the string from morse to english
function decrypt(message) {
  message += " "; // extra space added at the end to access the last morse code
  var decipher = "";
  var citext = "";
  var i = 0; // counter to keep track of space
  message.split("").forEach(letter => {
    // checks for space
    if (letter !== " ") {
      i = 0;
      citext += letter; // storing morse code of a single character
    }
    // in case of space
    else {
      // if i = 1 that indicates a new character
      i += 1;
      // if i = 2 that indicates a new word
      if (i === 2) {
        decipher += " "; // adding space to separate words
      } else {
        // accessing the keys using their values (reverse of encryption via array of values)
        decipher += Object.keys(MORSE_CODES)[CODE_VALS.indexOf(citext)];
        citext = "";
      }
    }
  });

  return decipher;
}

//===================RUN IT====================
var message1 = "ALICE KILED BOB";
var result1 = encrypt(message1.toUpperCase());
console.log(result1);

var message2 =
  "-.- . ...- .. -.  ... .--. .- -.-. . -.--  .. ...  -.- . -.-- ... . .-.  ... --- --.. .";
var result2 = decrypt(message2);
console.log(result2);
