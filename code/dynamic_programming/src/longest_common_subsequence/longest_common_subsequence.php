<?php 
function longestCommonSubsequence($x , $y) 
{ 
    $x_len = strlen($x); 
    $y_len = strlen($y) ; 

    for ($i = 0; $i <= $x_len; $i++) 
    { 
        for ($j = 0; $j <= $y_len; $j++) 
        { 
            if ($i == 0 || $j == 0) 
                $dp[$i][$j] = 0; 
            else if ($x[$i - 1] == $y[$j - 1]) 
                $dp[$i][$j] = $dp[$i - 1][$j - 1] + 1; 
            else
                $dp[$i][$j] = max($dp[$i - 1][$j], $dp[$i][$j - 1]); 
        } 
    } 

    return $dp[$x_len][$y_len]; 
} 

$a = "AGGTAB"; 
$b = "GXTXAYB";

echo "Length of LCS : ", longestCommonSubsequence($a, $b); 
