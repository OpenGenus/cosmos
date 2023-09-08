<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 *
 * @param int $n
 *
 * @return bool
 */
function isPerfectNumber($n)
{
    $sum = 0;
    for ($i = 1; $i < $n; $i++) {
        if ($n % $i === 0) {
            $sum += $i;
        }
    }
    return $sum === $n;
}

echo isPerfectNumber($number = 6) ? sprintf('%d is a perfect number.', $number) : sprintf('%d is not a perfect number.', $number);
