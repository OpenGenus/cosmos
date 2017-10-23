<?php
$intervalOne = 3;
$intervalTwo = 4;
$maxIteration = 10;
$precision = 0.001;

//example function = x³ - 4x² + 2
function f($x){
    return (($x ** 3) - (4 * ($x ** 2)) + 2);
}

//derivate 3x² - 8x
function df($x){
    return ((3 * ($x ** 2)) - (8 * $x));
}

function firstIterationValue($interN,$interM){
    $first = abs(df($interN)) >= abs(df($interM)) ? $interN : $interM;
    return $first;
}

function getXn($x){
    return ($x - (f($x)/df($x)));
}

for ($i=0; $i < $maxIteration; $i++) { 
    $xn = $i === 0 ? firstIterationValue($intervalOne,$intervalTwo) : getXn($xn);
    $dxn = df($xn);
    echo "I: {$i} | N: {$xn} <br>"; 
    if($i == $maxIteration-1){
        echo "Max Iteration Reached";
    }else if($xn <= $precision){
        echo "Precision reached";
		break;
    }
}