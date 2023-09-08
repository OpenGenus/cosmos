<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 *
 * Find all prime numbers up to any given n using Sieve of Eratosthenes.
 *
 * @param int $n
 *
 * @return array|integer
 */
function sieveOfEratosthenes($n)
{
    if ($n <= 1) {
        return -1;
    }
    $array = array_fill_keys(range(2, $n), true);
    for ($i = 2; $i <= (int) sqrt($n); $i++) {
        if ($array[$i] === true) {
            for ($j = $i ** 2; $j <= $n; $j += $i) {
                $array[$j] = false;
            }
        }
    }
    return array_keys($array, true);
}

echo implode(', ', sieveOfEratosthenes(365));
