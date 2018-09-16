<?php 
function russianPeasant($a,$b){
    $res = 0;
	while ($a >= 1){
		if($a%2 !== 0 || $b%2 !== 0){
            $res = $res + $b;
		}
        $a = $a/2;
        $b = $b*2;
    }
    return $res;
}

echo russianPeasant(6,4);