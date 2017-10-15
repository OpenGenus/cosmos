<?php
// Part of Cosmos by OpenGenus Foundation
function selection_sort($arr) {
    $n = count($arr);

    foreach ($arr as $k => $el) {
        $min = $k;

        for ($j = $k + 1; $j < $n; $j++) {
            if ($arr[$j] < $arr[$min]) {
                $min = $j;
            }
        }

        $hold = $el;
        $el = $arr[$min];
        $arr[$min] = $hold;
    }

    return $arr;
}


$test = [1, 3, 43, 2, 14, 53, 12, 87, 33];

print_r($test);
$sorted = selection_sort($test);

print_r($sorted);
