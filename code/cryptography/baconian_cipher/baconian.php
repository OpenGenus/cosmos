<?php
/**
* Bacon's (aka Baconian) cipher (PHP)
* based on https://en.wikipedia.org/wiki/Bacon%27s_cipher
* implemented by Stefano Amorelli <amoste@outlook.it>
* Part of Cosmos by OpenGenus Foundation
*/

class BaconianCipher
{
  private $mapping;

  function __construct() {
    $this->mapping = [];
    $this->initMapping();
  }

  public function encrypt($plainText) {
    if (!ctype_alpha($plainText)) {
      throw new Exception('Plaintext should be alphabetical strings (no spaces, symbols and numbers).');
    }
    $plainText      = strtoupper($plainText);
    $encryptedText  = [];
    foreach (str_split($plainText) as $character) {
      array_push($encryptedText, $this->mapping[$character]);
    }
    return implode(' ', $encryptedText);
  }

  public function decrypt($encryptedText) {
    $plainText = [];
    foreach (explode(' ', $encryptedText) as $character) {
      foreach ($this->mapping as $key => $value) {
        if ($value === $character) {
          $plainCharacter = $key;
          continue;
        }
      }
      array_push($plainText, $plainCharacter);
    }
    return implode('', $plainText);
  }

  private function initMapping() {
    $this->mapping['A'] = 'aaaaa';
    $this->mapping['B'] = 'aaaab';
    $this->mapping['C'] = 'aaaba';
    $this->mapping['D'] = 'aaabb';
    $this->mapping['E'] = 'aabaa';
    $this->mapping['F'] = 'aabab';
    $this->mapping['G'] = 'aabba';
    $this->mapping['H'] = 'aabbb';
    $this->mapping['I'] = 'abaaa';
    $this->mapping['J'] = 'abaab';
    $this->mapping['K'] = 'ababa';
    $this->mapping['L'] = 'ababb';
    $this->mapping['M'] = 'abbaa';
    $this->mapping['N'] = 'abbab';
    $this->mapping['O'] = 'abbba';
    $this->mapping['P'] = 'abbbb';
    $this->mapping['Q'] = 'baaaa';
    $this->mapping['R'] = 'baaab';
    $this->mapping['S'] = 'baaba';
    $this->mapping['T'] = 'baabb';
    $this->mapping['U'] = 'babaa';
    $this->mapping['V'] = 'babab';
    $this->mapping['W'] = 'babba';
    $this->mapping['X'] = 'babbb';
    $this->mapping['Y'] = 'bbaaa';
    $this->mapping['Z'] = 'bbaab';
  }
}


/* Example usage: 

$cipher    = new BaconianCipher();
  
$encrypted = $cipher->encrypt('LOREMIPSUMDOLOR');

$decrypted = $cipher->decrypt($encrypted);

echo $decrypted; // output: LOREMIPSUMDOLOR

*/