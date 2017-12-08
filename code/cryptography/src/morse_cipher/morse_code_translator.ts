// Program to convert morse code to ASCII and vice-versa

const MORSE_MAP = {
  A: '.-',
  B: '-...',
  C: '-.-.',
  D: '-..',
  E: '.',
  F: '..-.',
  G: '--.',
  H: '....',
  I: '..',
  J: '.---',
  K: '-.-',
  L: '.-..',
  M: '--',
  N: '-.',
  O: '---',
  P: '.--.',
  Q: '--.-',
  R: '.-.',
  S: '...',
  T: '-',
  U: '..-',
  V: '...-',
  W: '.--',
  X: '-..-',
  Y: '-.--',
  Z: '--..',
  '1': '.----',
  '2': '..---',
  '3': '...--',
  '4': '....-',
  '5': '.....',
  '6': '-....',
  '7': '--...',
  '8': '---..',
  '9': '----.',
  '0': '-----',
  ',': '--..--',
  '.': '.-.-.-',
  '?': '..--..',
  '/': '-..-.',
  '-': '-....-',
  '(': '-.--.',
  ')': '-.--.-',
}

/**
 * Encrypt a text string into morse code. One space implies
 * a different character, while two spaces implies a different word.
 * 
 * @param str The ASCII input string
 */
export function encrypt(str: string): string {
  let encrypted = '';
  str.toUpperCase().split('').forEach((char: string) => {
    if (char !== ' ') {
      encrypted += MORSE_MAP[char] + ' ';
    } else {
      encrypted += ' ';
    }
  })

  return encrypted;
}

/**
 * Convert a morse code string back into regular text.
 * 
 * @param str The Morse code input string
 */
export function decrypt(str: string): string {
  let decrypted = '';
  str.split('  ').forEach((word: string) => {
    word.split(' ').forEach((letter: string) => {
      decrypted += Object.keys(MORSE_MAP).filter(key => MORSE_MAP[key] === letter)[0];
    })
    // Add a space to split words
    decrypted += ' ';
  })
  return decrypted;
}

const input1 = 'Hello world.';
const input2 = '.... . .-.. .-.. ---  .-- --- .-. .-.. -.. .-.-.-';
const result1 = encrypt(input1);
const result2 = decrypt(input2);

console.log(`Encrypted text: ${result1}`);
console.log(`Decrypted text: ${result2}`);
