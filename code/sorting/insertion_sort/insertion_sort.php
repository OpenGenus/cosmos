<?php
// Part of Cosmos by OpenGenus Foundation
$array = array(0,1,6,7,6,3,4,2);

function insert_sort($array)
{
  for($i = 0; $i < count($array); $i++)
  {
    $val = $array[$i];
    $j = $i-1;
    while($j >= 0 && $array[$j] > $val)
    {
      $array[$j+1] = $array[$j];
      $j--;
    }
    $array[$j+1] = $val;
  }
  return $array;
}

print 'unsorted array';
echo "\n";
print_r($array);
print 'sorted array';
echo "\n";
print_r(insert_sort($array));

?>
