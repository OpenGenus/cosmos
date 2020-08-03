<?php
$x = 5;
$y = 10;

function myTest() {
    static $a=4;
    static $b=6;
    global $x,$y;
    $c = $a + $b;
    echo $c."<br>";
    $z = $x + $y;
    echo $z."<br>";
}

myTest();
echo $x+$y."<br>";
myTest();
 
?>