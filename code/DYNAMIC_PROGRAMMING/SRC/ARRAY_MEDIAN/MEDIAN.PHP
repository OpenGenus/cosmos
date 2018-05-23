<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * Finds median in array of numbers
 *
 * @param array $arr array of numbers
 * @return int median
 */
function median(array $arr)
{
    sort($arr);
    $cnt = count($arr);
    if ($cnt % 2) {
        return $arr[floor(($cnt - 1) / 2)];
    }
    return ($arr[floor($cnt / 2)] + $arr[floor($cnt / 2) - 1]) / 2;
}

echo "median\n";
$test_data = [
    [[-1], -1],
    [[0], 0],
    [[1], 1],
    [[-1, 0, 1], 0],
    [[1, 2, 3], 2],
    [[-1, -2, -3], -2],
    [[1, 2.5, 3], 2.5],
    [[-1, -2.5, -3], -2.5],
    [[1, 2, 2, 4], 2],
    [[1, 2, 3, 4], 2.5],
    [[2, 2, 1, 4], 2],
    [[3, 2, 1, 4], 2.5],
    [[-1, -2, -2, -4], -2],
    [[-1, -2, -3, -4], -2.5],
];
foreach ($test_data as $test_case) {
    $input = $test_case[0];
    $expected = $test_case[1];
    $result = median($input);
    printf(
        "  input %s, expected %s, got %s: %s\n",
        str_replace(["\n", '  '], ['', ' '], var_export($input, true)),
        var_export($expected, true),
        var_export($result, true),
        ($expected === $result) ? 'OK' : 'FAIL'
    );
}
