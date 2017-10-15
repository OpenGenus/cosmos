<?php
# Part of Cosmos by OpenGenus Foundation

# An Armstrong number is the one whose value is equal to the sum of the cubes of its digits.



// declaring variable
$number = 407;   // demo number
$sum = 0;   // varibale to store the sum of number
$dup = $number;   // duplicate number to traverse through digit

// loop will work untill and unless all digits are being processed
while($dup != 0)
{
  $sum = $sum + pow( $dup%10 ,3);  // power 3 of last digit
  $dup = $dup / 10;  // deleteing last digit
}

if($number == $sum)
{
echo "$number is an Armstrong number";
}
else
{
echo "$number is not an armstrong number";
}
?>
