<?php 
function longestRepeatingSubsequence($str) 
{ 
    $n = strlen($str); 
    $dp = array(array());

    for ($i = 0; $i <= $n; $i++) 
        for ($j = 0; $j <= $n; $j++) 
            $dp[$i][$j] = 0; 

    for ($i = 1; $i <= $n; $i++) 
    { 
        for ($j = 1; $j <= $n; $j++) 
        { 
            if ($str[$i - 1] == $str[$j - 1] && $i != $j) 
                $dp[$i][$j] = 1 + $dp[$i - 1][$j - 1];	 
            else
                $dp[$i][$j] = max($dp[$i][$j - 1], $dp[$i - 1][$j]); 
        } 
    }

    return $dp[$n][$n]; 
} 

$str = "aabb"; 
echo "Length of LRS : ", longestRepeatingSubsequence($str); 
