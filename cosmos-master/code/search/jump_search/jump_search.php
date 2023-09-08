<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 *
 * @param array $array
 * @param int   $search
 *
 * @return int
 */
function jumpSearch(array $array, $search)
{
    list ($count, $step, $previous) = [$count = count($array), (int) sqrt($count), 0];
    while ($array[min($step, $count) - 1] < $search) {
        $previous = $step;
        $step += (int) sqrt($count);
        if ($previous >= $count) {
            return -1;
        }
    }
    while ($array[$previous] < $search) {
        $previous++;
        if ($previous === min($step, $count)) {
            return -1;
        }
    }
    return $array[$previous] === $search ? $previous : -1;
}

echo sprintf("Position of %d is %d\n", $search = 33, jumpSearch($array = [7, 11, 13, 33, 66], $search));
