<?php

/* Part of Cosmos by OpenGenus Foundation */

/* Usage:

  magicSquare(3);

*/

magicSquare(3);

function magicSquare($num) {
	$magicSquare = array();

	for ($row = 0; $row < $num; $row++) {
		for ($col = 0; $col < $num; $col++) {
			$rowMatrix = ((($num + 1) / 2 + $row + $col) % $num);
			$colMatrix = ((($num + 1) / 2 + $row + $num - $col - 1) % $num) + 1;
			$magicSquare[$row][$col] = ((($rowMatrix * $num) + $colMatrix));
		}
	}

	foreach ($magicSquare as $rows) {
		echo implode("\t", $rows)."\r\n";
	}
}
