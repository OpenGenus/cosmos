<?php
/* Part of Cosmos by OpenGenus Foundation */

const LATIN_TO_MORSE_DICTIONARY = [
    'A' => '.-',
    'B' => '-...',
    'C' => '-.-.',
    'D' => '-..',
    'E' => '.',
    'F' => '..-.',
    'G' => '--.',
    'H' => '....',
    'I' => '..',
    'J' => '.---',
    'K' => '-.-',
    'L' => '.-..',
    'M' => '--',
    'N' => '-.',
    'O' => '---',
    'P' => '.--.',
    'Q' => '--.-',
    'R' => '.-.',
    'S' => '...',
    'T' => '-',
    'U' => '..-',
    'V' => '...-',
    'W' => '.--',
    'X' => '-..-',
    'Y' => '-.--',
    'Z' => '--..',
    '0' => '-----',
    '1' => '.----',
    '2' => '..---',
    '3' => '...--',
    '4' => '....-',
    '5' => '.....',
    '6' => '-....',
    '7' => '--...',
    '8' => '---..',
    '9' => '----.',
    ',' => '--..--',
    '.' => '.-.-.-',
    '?' => '..--..',
    '/' => '-..-.',
    '-' => '-....-',
    '(' => '-.--.',
    ')' => '-.--.-',
    ' ' => ' ',
];

// Converts $message to morse code
function encrypt(string $message): string {
    $chars = str_split(strtoupper(trim($message)));
    $morse = '';
    foreach ($chars AS $char) {
        if (array_key_exists($char, LATIN_TO_MORSE_DICTIONARY)) {
            $morse .= LATIN_TO_MORSE_DICTIONARY[$char];
        }
        $morse .= ' ';
    }
    return rtrim($morse);
}

// Decrypts morse code
function decrypt(string $morse): string {
    $tokens = explode(' ', $morse);
    $message = '';
    $morse_to_latin_dictionary = array_flip(LATIN_TO_MORSE_DICTIONARY);
    foreach ($tokens AS $token) {
        if (array_key_exists($token, $morse_to_latin_dictionary)) {
            $message .= $morse_to_latin_dictionary[$token];
        }
        else if ('' === $token){
            $message .= ' ';
        }
    }
    return rtrim($message);
}


echo 'Encoding "Alice":' . PHP_EOL;
echo encrypt('Alice') . PHP_EOL . PHP_EOL;

echo 'Decoding ".... ..  -... --- -...":' . PHP_EOL;
echo decrypt('.... ..  -... --- -...');