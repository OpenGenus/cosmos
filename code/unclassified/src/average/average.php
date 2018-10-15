<?php
// finds the average of an array of numbers.

function getAverage($numbers) {
  $sum = 0;
  for($i=0; $i<count($numbers); $i++) {
    $sum += $numbers[$i];
  }
  return ($sum / count($numbers));
}

echo getAverage([10,20,30,40,50]);

?>