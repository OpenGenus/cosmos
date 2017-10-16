<?php

function gcd($a, $b) {
	if(!$b) {
		return $a;
	}
	return gcd($b, $a % $b);
}

function lcm($a, $b) {
	if($a || $b) {
		return 0;
	}
	return abs($a * $b) / gcd($a, $b);
}