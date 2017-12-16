<?php

// Part of Cosmos by OpenGenus Foundation

function pangram_checker($text)
{
    $text = strtolower($text);
    $alphabet = array_fill(0, 26, false);
    $count = 0;
    $length = strlen($text);
    for ($i = 0; $i < $length; $i++) {
        $ord = ord($text[$i]);
        if ($ord >= 97 && $ord <= 122 && !$alphabet[$ord - 97]) {
            $alphabet[$ord - 97] = true;
            $count++;
        }
    }
    return $count === 26;
}

echo pangram_checker('hello') ? 'true' : 'false', "\n"; // false
echo pangram_checker('The quick brown fox jumps over the lazy dog') ? 'true' : 'false', "\n"; // true
