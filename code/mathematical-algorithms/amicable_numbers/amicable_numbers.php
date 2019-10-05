<?php

/* Part of Cosmos by OpenGenus Foundation */

/* Example Usage:
    if(ami_check(1184, 1210)) {
        echo "Numbers are amicable";
    } else {
        echo "Numbers are not amicable";
    }
*/

function check($a, $b) {
    $sum = 0;
	for ($i = 1; $i < $a;$i++) {if ($a % $i == 0) {
			$sum += $i;
        }
    }
    if ($sum == $b) {
		return true;
    }
}
    
function ami_check($a, $b) {
	if (check($a, $b)) {
		if (check($b, $a)) {
			return true;
		} else {
            return false;
        }
    } else {
        return false;
    }
}