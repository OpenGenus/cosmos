<?php

/* Part of Cosmos by OpenGenus Foundation */

/* Example Usage:
	print_r(pigeonholeSort([9, 2, 17, 5, 16]));
*/

function pigeonholeSort($array) {
	$min = min($array);
	$max = max($array);
	$numHoles = $max - $min + 1;

	$holes = array_fill(0, $numHoles, 0);

	foreach ($array as $item) {
		$holes[$item - $min] += 1;
	}

	$sortedArray = [];

	for ($i = 0; $i < count($holes); $i++) {
		while ($holes[$i] > 0) {
			array_push($sortedArray, $i + $min);
			$holes[$i] -= 1;
		}
	}

	return $sortedArray;

}
