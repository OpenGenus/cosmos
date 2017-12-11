<?php

/* Part of Cosmos by OpenGenus Foundation */

/* Usage:

  echo (fuzzySearch('B', 'ACC')) ? 'true' : 'false';

*/

function fuzzySearch($needle, $haystack)
{
	if (strlen($needle) > strlen($haystack)) {
		return false;
	}

	if (strlen($needle) === strlen($haystack)) {
		return $needle === $haystack;
	}

	for ($i = 0; $i < strlen($needle); $i++) {
		$nth_character = substr($needle, $i, 1);

		foreach (str_split($haystack) as $char) {
			if($char === $nth_character) {
				return true;
			}
		}
		return false;
	}
}
