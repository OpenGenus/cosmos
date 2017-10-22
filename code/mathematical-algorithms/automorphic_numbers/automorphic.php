<?php

function isAutomorphic(int $num)
{
    return endsWith(strval($num * $num), strval($num));
}

function endsWith($haystack, $needle)
{
    $length = strlen($needle);

    return $length === 0 ||
    (substr($haystack, -$length) === $needle);
}

echo "Automorphic number\n";

$test_data = [
    0  => true,
    9  => false,
    5  => true,
    6  => true,
    7  => false,
    8  => false,
    25 => true,
    30 => false,
];

foreach ($test_data as $input => $expected) {

    $result = isAutomorphic($input);

    printf(
        "  input %d, expected %s, got %s: %s\n",
        $input,
        ($expected ? 'true' : 'false'),
        ($result ? 'true' : 'false'),
        ($expected === $result) ? 'OK' : 'FAIL'
    );
}