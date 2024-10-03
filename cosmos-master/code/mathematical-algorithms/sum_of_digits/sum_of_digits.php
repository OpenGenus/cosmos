<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * Calculates sum of digits in number
 *
 * @param int $num number
 * @return int sum of digits in number
 */
function sum_of_digits(int $num)
{
    $sum = 0;
    $str = (string)$num;
    $len = strlen($num);
    for($i = 0; $i < $len; $i++) {
        $sum += (int)$str[$i];
    }
    return $sum;
}

echo "sum of digits\n";
echo "  12345: " . sum_of_digits(12345) . "\n";
echo "  54321: " . sum_of_digits(54321) . "\n";
echo "  0: " . sum_of_digits(0) . "\n";
echo "  12: " . sum_of_digits(12) . "\n";
