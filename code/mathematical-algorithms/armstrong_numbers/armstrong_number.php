<?php
function is_armstrong($number)
{
  $sum = 0;
  $dupli = $number;
  while($dupli != 0)
  {
    $digit = $dupli % 10;
    $sum += $digit * $digit * $digit;
    $dupli/=10;
  }
  if ($sum == $number)
    return true;
  else
    return false;
}


if (is_armstrong(371))
  echo "yes";
else
  echo "no";


?>
