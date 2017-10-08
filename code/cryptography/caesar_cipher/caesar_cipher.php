<?php
/* Part of Cosmos by OpenGenus Foundation */

const REF = 'AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz';

function caesar_cipher(string $message, int $shift): string {
    $shift %= 26;
    $ref_shifted = substr(REF, $shift * 2) . substr(REF, 0, $shift * 2);
    return strtr($message, REF, $ref_shifted);
}

echo 'Encoding "Hello World", using a right shift of 10:' . PHP_EOL;
echo caesar_cipher('Hello World', 10) . PHP_EOL . PHP_EOL;

echo 'Decoding "byFFI qILFx", using a left shift of 6:' . PHP_EOL;
echo caesar_cipher('byFFI qILFx', -6);