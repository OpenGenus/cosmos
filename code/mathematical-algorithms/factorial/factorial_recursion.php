<?php

/**
 * Recursive factorial
 *
 * Part of Cosmos by OpenGenus Foundation
 *
 * Note: To run this script, you need PHP >= 7.0
 *
 * @author Lucas Soares Candalo <candalolucas@gmail.com>
 */

function factorial(int $n)
{
    if ($n == 0) {
        return 1;
    }
    return $n * factorial($n - 1);
}

$n = intval(readline("Enter a number: "));
if ($n < 0) {
    die("Number must be greater than 0");
}
echo factorial($n);
