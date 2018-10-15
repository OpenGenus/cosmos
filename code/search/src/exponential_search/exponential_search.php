<?php

$dontPrintBinarySearchTest = true;
require_once '../binary_search/binary_search.php';

/**
 * Part of Cosmos by OpenGenus Foundation
 *
 * @param array $array
 * @param int   $search
 *
 * @return int
 */
function exponentialSearch(array $array, $search)
{
    if (($count = count($array)) === 0) {
        return -1;
    }
    $i = 1;
    while ($i < $count && $array[$i] < $search) {
        $i *= 2;
    }
    return binarySearch($array, $i / 2, min($i, $count), $search);
}

echo sprintf("Position of %d is %d\n", $search = 13, exponentialSearch($array = [7, 11, 13, 33, 66], $search));
