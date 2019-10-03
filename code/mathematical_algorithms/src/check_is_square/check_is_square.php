<?php
// Part of Cosmos by OpenGenus Foundation 

// function to check if a number is
function check($numbers)
{
  foreach ($numbers as $number)  // traversing through each number
  {
    $chk = (string)sqrt($number) ;  // sqrt returns float which is converted to string by explixit type casting
    if(strpos($chk,".")) // checking if there is decimal or not
    echo "$number is not a perfect square<br>";
    else
    echo "$number is a perfect square<br>";
  }
}

// array of numbers to be performed
$numbers = array(1,2,3,4,5,6,7,8,9,10);
check($numbers); // calling the function
 ?>
