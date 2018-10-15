<?php
// Part of Cosmos by OpenGenus Foundation
function bucket_sort($my_array) {
  $n = sizeof($my_array);
  $buckets = array();
// Initialize the buckets.
  for ($i = 0; $i < $n; $i++) {
    $buckets[$i] = array();
  }
// Put each element into matched bucket.
  foreach ($my_array as $i) {
    array_push($buckets[ceil($i)], $i);
  }
// Sort elements in each bucket using insertion sort.
 $j = 0;
  for ($i = 0; $i < $n; $i++)
	  {
// sort only non-empty bucket
    if (!empty($buckets[$i])) {
      insertion_sort($buckets[$i]);

// Move sorted elements in the bucket into original array.
	  foreach ($buckets[$i] as $el) {
        $my_array[$j++] = $el;
      }
    }
  }
return $my_array;
}
function insertion_sort($my_array, $fn = 'comparison_function') {
  if (!is_array($my_array) || !is_callable($fn)) return;
  for ($i = 1; $i < sizeof($my_array); $i++) {
    $key = $my_array[$i];
    $j = $i - 1; // this will be in $b in comparison function
    while ( $j >= 0 && $fn($key, $my_array[$j]) ) {
      $my_array[$j + 1] = $my_array[$j];
      $j = $j - 1; // shift right
    }
    $my_array[$j + 1] = $key;
  }
}
//Following function used to compare each element.
function comparison_function($a, $b) {
  return $a < $b;
}
$array = array(7,6,0,1,5,3,4,2);
print 'unsorted array';
echo "\n";
print_r($array);
print 'sorted array';
echo "\n";
print_r(bucket_sort($array));
?>
