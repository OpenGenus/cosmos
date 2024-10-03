<?php

    function getBiggest($array)
    {
        rsort($array);
        return $array[0];
    }

    echo getBiggest([1, 2, 3, 4, 5]);           // 5
    echo "\n";
    echo getBiggest([10, 20, 30, 80, 70]);      // 80
    echo "\n";
    echo getBiggest([-1, -10, 0, -20, -1.6]);   // 0

?>