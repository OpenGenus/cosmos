<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * Converts binary number to decimal number
 *
 * @param int $bin binary number
 * @return int decimal number
 */
function binary_to_decimal(int $bin)
{
    $arr = array_map('intval', str_split($bin));
    $cnt = count($arr);
    $dec = 0;
    for ($i = 1; $i < $cnt + 1; $i++) {
        $dec += $arr[$i - 1] * (2 ** ($cnt - $i));
    }
    return $dec;
}


/**
 * Converts decimal number to binary number
 *
 * @param int decimal number
 * @return int $bin binary number
 */
function decimal_to_binary(int $dec)
{
    $i = 1;
    $bin = 0;
    while ($dec > 0) {
        $rem = $dec % 2;
        $bin = $bin + ($i * $rem);
        $dec = floor($dec / 2);
        $i *= 10;
    }
    return $bin;
}

echo "binary_to_decimal\n";
$test_data = [
    [0, 0],
    [1, 1],
    [10, 2],
    [101, 5],
    [1001, 9],
    [1010, 10],
    [1001001010100, 4692],
    [1001011110100, 4852],
];
foreach ($test_data as $test_case) {
    $input = $test_case[0];
    $expected = $test_case[1];
    $result = binary_to_decimal($input);
    printf(
        "  input %d, expected %s, got %s: %s\n",
        $input,
        var_export($expected, true),
        var_export($result, true),
        ($expected === $result) ? 'OK' : 'FAIL'
    );
}

echo "decimal_to_binary\n";
$test_data = [
    [0, 0],
    [1, 1],
    [2, 10],
    [5, 101],
    [9, 1001],
    [10, 1010],
    [4692, 1001001010100],
    [4852, 1001011110100],
];
foreach ($test_data as $test_case) {
    $input = $test_case[0];
    $expected = $test_case[1];
    $result = decimal_to_binary($input);
    printf(
        "  input %d, expected %s, got %s: %s\n",
        $input,
        var_export($expected, true),
        var_export($result, true),
        ($expected === $result) ? 'OK' : 'FAIL'
    );
}
