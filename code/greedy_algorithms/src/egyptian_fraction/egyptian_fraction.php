
<?php 
// Part of Cosmos by OpenGenus
// PHP program to print a fraction  
// in Egyptian Form using Greedy 
// Algorithm 
  
function printEgyptian($nr, $dr) 
{ 
    // If either numerator or  
    // denominator is 0 
    if ($dr == 0 || $nr == 0) 
        return; 
  
    // If numerator divides denominator,  
    // then simple division makes the  
    // fraction in 1/n form 
    if ($dr % $nr == 0) 
    { 
        echo "1/", (int)$dr / $nr; 
        return; 
    } 
  
    // If denominator divides numerator,  
    // then the given number is not fraction 
    if ($nr%$dr == 0) 
    { 
        echo (int)($nr / $dr); 
        return; 
    } 
  
    // If numerator is more than denominator 
    if ($nr > $dr) 
    { 
        echo (int)($nr/$dr), " + "; 
        printEgyptian($nr % $dr, $dr); 
        return; 
    } 
  
    // We reach here dr > nr and dr%nr is  
    // non-zero. Find ceiling of dr/nr and  
    // print it as first fraction 
    $n = (int)($dr / $nr ) + 1; 
    echo "1/" , $n , " + "; 
  
    // Recur for remaining part 
    printEgyptian($nr * $n - $dr, $dr * $n); 
} 
  
// Driver Code 
$nr = 6; 
$dr = 14; 
echo "Egyptian Fraction Representation of ", 
                    $nr, "/", $dr, " is\n "; 
printEgyptian($nr, $dr); 

?> 
