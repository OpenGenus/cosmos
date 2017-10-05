<?php

/**
 * @param array $array
 * @param int   $low
 * @param int   $high
 * @param int   $target
 *
 * @return int
 */
function binarySearch(array $array, $low, $high, $target)
{
    if ($high >= $low) {
        $middle = (int) ($low + ($high - $low) / 2);
        if ($array[$middle] === $target) {
            return $middle;
        } else if ($array[$middle] > $target) {
            return binarySearch($array, $low, $middle - 1, $target);
        } else {
            return binarySearch($array, $middle + 1, $high, $target);
        }
    }
    return -1;
}

echo sprintf(
    "Position of %d is %d\n",
    $search = 33, binarySearch($array = [7, 11, 13, 33, 66], 0, count($array) - 1, $search)
);
