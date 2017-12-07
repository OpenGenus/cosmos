<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * Finds the greatest digit in number
 *
 * @param int $num number
 * @return int greatest digit
 */
function greatest_digit_in_number(int $num)
{
    return max(array_map('intval', str_split($num)));
}

echo "greatest digit in number\n";
$test_data = [
    [0, 0],
    [9, 9],
    [11, 1],
    [99, 9],
    [19, 9],
    [91, 9],
    [10000, 1],
    [1000090, 9],
];
foreach ($test_data as $test_case) {
    $input = $test_case[0];
    $expected = $test_case[1];
    $result = greatest_digit_in_number($input);
    printf(
        "  input %d, expected %s, got %s: %s\n",
        $input,
        var_export($expected, true),
        var_export($result, true),
        ($expected === $result) ? 'OK' : 'FAIL'
    );
}
