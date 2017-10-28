<?php
// Part of Cosmos by OpenGenus Foundation */

function columns($my_array) {
    if (count($my_array) == 0)
        return array();
    else if (count($my_array) == 1)
        return array_chunk($my_array[0], 1);

     array_unshift($my_array, NULL);

    // array_map(NULL, $my_array[0], $my_array[1], ...)
     
    $transpose = call_user_func_array('array_map', $my_array);
    return array_map('array_filter', $transpose);
}

function bead_sort($my_array) {
    foreach ($my_array as $e)
        $poles []= array_fill(0, $e, 1);
    return array_map('count', columns(columns($poles)));
}

$test_array = array(3, 2, 5, 4, 1, 100);

echo "\nOriginal Array :\n";
echo implode(', ',$test_array );
echo "\nSorted Array :\n";
echo implode(', ',bead_sort($test_array)). PHP_EOL;

?>