<?php
/**
* Vigenère cipher (PHP)
* based on https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher
* implemented by Stefano Amorelli <amoste@outlook.it>
* Part of Cosmos by OpenGenus Foundation
*/

class VigenereCipher
{
 public function encrypt($plainText, $key) {

  if (!ctype_alpha($plainText) || !ctype_alpha($key)) {
   throw new Exception('Plaintext and key should be alphabetical strings (no spaces, symbols and numbers).');
  }

  $plainText  = strtolower($plainText);
  $key        = strtolower($key);
  $encryptedText = [];
  $i          = 0;

  foreach (str_split($plainText) as $character) {
   array_push($encryptedText, $this->encryptCharacter($character, $key[$i]));
   $i++;
   $i = $i % strlen($key);
  }
  return implode('', $encryptedText);

 }

 public function decrypt($encryptedText, $key) {

  if (!ctype_alpha($encryptedText) || !ctype_alpha($key)) {
   throw new Exception('Encrypted text and key should be alphabetical strings (no spaces, symbols and numbers).');
  }

  $encryptedText = strtolower($encryptedText);
  $key           = strtolower($key);
  $plainText     = [];
  $i             = 0;

  foreach (str_split($encryptedText) as $character) {
   array_push($plainText, $this->decryptCharacter($character, $key[$i]));
   $i++;
   $i = $i % strlen($key);
  }
  return implode('', $plainText);

 }

 private function normalizeAscii($character) {
  return ord($character) - ord('a');
 }

 private function returnAscii($normalizedAscii) {
  return chr($normalizedAscii + ord('a'));
 }

 private function encryptCharacter($plainCharacter, $keyCharacter) {
  return $this->returnAscii(($this->normalizeAscii($plainCharacter) + $this->normalizeAscii($keyCharacter)) % 26);
 }

 private function decryptCharacter($encryptedCharacter, $keyCharacter) {
  return  $this->returnAscii(($this->normalizeAscii($encryptedCharacter) - $this->normalizeAscii($keyCharacter) + 26) % 26);
 }
}

/* Example usage: 

$cipher    = new VigenereCipher();

$secret    = 'mysecret';
  
$encrypted = $cipher->encrypt('loremipsumdolor', $secret);

$plain     = $cipher->decrypt($encrypted, $secret);

echo $plain;

*/
