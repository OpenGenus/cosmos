"use strict";

class Viegenere {
  static alphabetLen_() {
    return Viegenere.ALPHABET.length;
  }
  static encript(text, key) {
    let result = "";
    const preparedText = text.replace(new RegExp("\\s", "g"), "").toLowerCase();
    const preparedKey = key.toLowerCase();
    const alphabetLen = Viegenere.alphabetLen_();
    for (let i = 0; i < preparedText.length; i++) {
      const char = preparedText[i];
      const keyChar = preparedKey[i % preparedKey.length];
      const shift = Viegenere.ALPHABET.indexOf(keyChar) % alphabetLen;
      const indexInAlphabet = Viegenere.ALPHABET.indexOf(char);
      result += Viegenere.ALPHABET[(indexInAlphabet + shift) % alphabetLen];
    }
    return result;
  }

  static decript(encripted, key) {
    let result = "";
    const preparedKey = key.toLowerCase();
    const alphabetLen = Viegenere.alphabetLen_();
    for (let i = 0; i < encripted.length; i++) {
      const char = encripted[i];
      const keyChar = preparedKey[i % preparedKey.length];
      let shift =
        Viegenere.ALPHABET.indexOf(char) - Viegenere.ALPHABET.indexOf(keyChar);
      shift = shift >= 0 ? shift : alphabetLen + shift;
      result += Viegenere.ALPHABET[shift];
    }
    return result;
  }
}

Viegenere.ALPHABET = "abcdefghijklmnopqrstuvwxyz";

const key = "LEMONLEMONLE";
const text = "Lorem ipsum dolor sit amet";
const encripted = Viegenere.encript(text, key);
const decripted = Viegenere.decript(encripted, key);

console.log(encripted);
console.log(decripted);
