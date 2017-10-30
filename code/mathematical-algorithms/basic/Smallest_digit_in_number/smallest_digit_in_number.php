<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * Finds the smallest digit in number
 *
 * @param int $num number
 * @return int smallest digit
 */
function smallest_digit_in_number(int $num)
{
    return min(array_map('intval', str_split($num)));
}

echo "smallest digit in number\n";
$test_data = [
    [0, 0],
    [9, 9],
    [11, 1],
    [99, 9],
    [19, 1],
    [91, 1],
    [10000, 0],
    [1000090, 0],
];
foreach ($test_data as $test_case) {
    $input = $test_case[0];
    $expected = $test_case[1];
    $result = smallest_digit_in_number($input);
    printf(
        "  input %d, expected %s, got %s: %s\n",
        $input,
        var_export($expected, true),
        var_export($result, true),
        ($expected === $result) ? 'OK' : 'FAIL'
    );
}
