<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 *
 * @param array $array
 * @param int   $search
 *
 * @return int
 */
function interpolationSearch(array $array, $search)
{
    list ($low, $high) = [0, count($array) - 1];
    while (($array[$high] !== $array[$low]) && ($search >= $array[$low]) && ($search <= $array[$high])) {
        $middle = $low + (($search - $array[$low]) * ($high - $low) / ($array[$high] - $array[$low]));
        if ($array[$middle] < $search) {
            $low = $middle + 1;
        } else if ($search < $array[$middle]) {
            $high = $middle - 1;
        } else {
            return $middle;
        }
    }
    return $search === $array[$low] ? $low : -1;
}

echo sprintf("Position of %d is %d\n", $search = 33, interpolationSearch($array = [7, 11, 13, 33, 66], $search));
