<?php
function reverse_number($numbers) {
  $string =  (string) $numbers;
  $result = "";
  $length = strlen($string);

  for ($i = $length - 1; $i >= 0; $i--) {
    $result .= $string[$i];
  }

  return  $result ;
}

echo reverse_number(123456789);
