<?php
// Part of Cosmos by OpenGenus Foundation */

$array = [0,1,6,7,6,3,4,2];

function bubble_sort(array $array)
{
	do {
		$swapped = false;
		for( $i = 0, $c = count($array) - 1; $i < $c; $i++) {
			if($array[$i] > $array[$i + 1]) {
				list($array[$i + 1], $array[$i]) = array($array[$i], $array[$i + 1]);
				$swapped = true;
			}
		}
	} while($swapped);

	return $array;
}

print 'unsorted array';
echo "\n";
print_r($array);
print 'sorted array';
echo "\n";
print_r(bubble_sort($array));
