<?php

// Part of Cosmos by OpenGenus Foundation

function pangram_checker($text) {
    $text = strtolower($text);
    $alphabet = array_fill(0, 26, FALSE);
    $count = 0;
    $length = strlen($text);
    for ($i = 0; $i < $length; $i++) {
        $ord = ord($text[$i]);
        if ($ord >= 97 && $ord <= 122 && !$alphabet[$ord - 97]) {
            $alphabet[$ord - 97] = TRUE;
            $count++;
        }
    }
    return $count === 26;
}

echo pangram_checker('hello') ? 'TRUE' : 'FALSE', "\n"; // FALSE
echo pangram_checker('The quick brown fox jumps over the lazy dog') ? 'TRUE' : 'FALSE', "\n"; // TRUE
