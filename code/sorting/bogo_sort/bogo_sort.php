<?php

/* Part of Cosmos by OpenGenus Foundation */

/* Example Usage:
    print_r(bogosort([5,17,-13,15,14,16]));
*/

function isSorted($array)
{
	if (count($array) <= 1) {
		return true;
	}

	for ($i = 1; $i < count($array); $i++) {
		if ($array[$i] < $array[$i-1]) {
			return false;
		}
	}
	return true;
}

function bogosort($array)
{
	while (!isSorted($array)) {
		shuffle($array);
	}

	return $array;
}