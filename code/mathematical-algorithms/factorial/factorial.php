<?php
// use a apache server to view

/*
  the factorial of a non-negative integer n, denoted by n!, is the
  product of all positive integers less than or equal to n.
*/

$number = 5; // declared a number

$factorial = 1;  // muntipying object

for ($i=$number; $i > 0; $i--) {   // loop from number to 1   (here -> 5 * 4 * 3 * 2 * 1)
  $factorial *= $i;   // overwriting $factorial to get desired value
}


// printing the value
echo "<br>FACTORIAL FROM INBULIT FUNCTION : $factorial";
?>
