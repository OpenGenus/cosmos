<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * Finds next greater number containing only digits from input number
 *
 * @param int $num input number
 * @return int|false next greater number or false if it does not exist
 */
function next_larger_number(int $num)
{
    $arr = array_map('intval', str_split($num));
    $cnt = count($arr);
    for ($i = $cnt - 1; $i > 0; $i--) {
        if ($arr[$i] > $arr[$i - 1]) {
            break;
        }
    }
    if ($i === 0) {
        return false;
    }
    $i--;
    $i_val = $arr[$i];
    $smallest = 9;
    $smallest_idx = 0;
    for ($j = $i + 1; $j < $cnt; $j++) {
        if ($arr[$j] > $i_val && $arr[$j] <= $smallest) {
            $smallest = $arr[$j];
            $smallest_idx = $j;
        }
    }
    $arr[$smallest_idx] = $arr[$i];
    $arr[$i] = $smallest;
    $tail = array_slice($arr, $i + 1);
    sort($tail);
    array_splice($arr, $i + 1, count($tail), $tail);
    return (int)implode('', $arr);
}

echo "next larger number\n";
$test_data = [
    [1, false],
    [15, 51],
    [51, false],
    [697, 769],
    [796, 967],
    [799, 979],
    [5674, 5746],
    [1234554321, 1235123445],
    [9876556789, 9876556798],
    [98765567890, 98765567908],
    [12345543214, 12345543241],
    [111110, false],
    [100001, 100010],
    [191919, 191991],
    [919191, 919911],
    [54321, false],
    [14321, 21134],
    [99999, false],
];
foreach ($test_data as $test_case) {
    $input = $test_case[0];
    $expected = $test_case[1];
    $result = next_larger_number($input);
    printf(
        "  input %d, expected %s, got %s: %s\n",
        $input,
        var_export($expected, true),
        var_export($result, true),
        ($expected === $result) ? 'OK' : 'FAIL'
    );
}
