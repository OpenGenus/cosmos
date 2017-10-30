<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 *
 * @param int $n
 *
 * @return integer
 */
function fibonacci($n)
{
    return round(((5 ** .5 + 1) / 2) ** $n / 5 ** .5);
}

echo sprintf('Fibonacci of %d is %d.', $number = 10, fibonacci($number));
