// String algorithms | morse code | javascript
// Part of OpenGenus Foundation

const TO_MORSE_MAP = {
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
  "0": "-----"
};

const FROM_MORSE_MAP = Object.keys(TO_MORSE_MAP).reduce(
  (map, key) => Object.assign(map, { [TO_MORSE_MAP[key]]: key }),
  {}
);

const fromChar = char => TO_MORSE_MAP[char];

const toChar = seq => FROM_MORSE_MAP[seq];

const encode = input => input.split("").map(fromChar);

const decode = input => input.map(toChar).join("");

// Tests
const assert = require("assert");
assert.deepEqual(encode("FOO"), ["..-.", "---", "---"]);
assert.deepEqual(decode(["..-.", "---", "---"]), "FOO");
