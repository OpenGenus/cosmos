<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 *
 * @param array $array
 * @param int   $low
 * @param int   $high
 * @param int   $search
 *
 * @return int
 */
function ternarySearch(array $array, $low, $high, $search)
{
    if ($high >= $low) {
        list($lowMiddle, $highMiddle) = [$low + ($high - $low) / 3, $low + 2 * ($high - $low) / 3];
        if ($search === $array[$lowMiddle]) {
            return $lowMiddle;
        } else if ($search === $array[$highMiddle]) {
            return $highMiddle;
        } else if ($search < $array[$highMiddle]) {
            return ternarySearch($array, $low, $lowMiddle, $search);
        } else if ($search > $array[$lowMiddle] && $search < $array[$highMiddle]) {
            return ternarySearch($array, $lowMiddle, $highMiddle, $search);
        } else {
            return ternarySearch($array, $highMiddle, $high, $search);
        }
    }
    return -1;
}

echo sprintf(
    "Position of %d is %d\n",
    $search = 33, ternarySearch($array = [7, 11, 13, 33, 66], 0, count($array) - 1, $search)
);
