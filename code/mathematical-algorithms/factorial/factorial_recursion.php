<?php

function factorial($x) {
    if($x == 0) return 1;
    return $x * factorial($x - 1);
}

echo factorial(10);

?>
