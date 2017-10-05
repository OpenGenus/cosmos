<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 *
 * @param array $array
 * @param int   $search
 *
 * @return int
 */
function linearSearch(array $array, $search)
{
    $count = count($array);
    for ($i = 0; $i < $count; $i++) {
        if ($array[$i] === $search) {
            return $i;
        }
    }
    return -1;
}

echo sprintf("Position of %d is %d\n", $search = 33, linearSearch($array = [7, 11, 13, 33, 66], $search));
