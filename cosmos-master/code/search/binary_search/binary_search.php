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
function binarySearch(array $array, $low, $high, $search)
{
    if ($high >= $low) {
        $middle = (int) ($low + ($high - $low) / 2);
        if ($array[$middle] === $search) {
            return $middle;
        } else if ($array[$middle] > $search) {
            return binarySearch($array, $low, $middle - 1, $search);
        } else {
            return binarySearch($array, $middle + 1, $high, $search);
        }
    }
    return -1;
}

if (!isset($dontPrintBinarySearchTest)) {
    echo sprintf(
        "Position of %d is %d\n",
        $search = 33, binarySearch($array = [7, 11, 13, 33, 66], 0, count($array) - 1, $search)
    );
}
