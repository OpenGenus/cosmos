<?php
//license under the MIT https://goo.gl/JNRTRM
function bucket_sort($my_array) {
  $n = sizeof($my_array);
  $buckets = array();
// Initialize the buckets.
  for ($i = 0; $i < $n; $i++) {
    $buckets[$i] = array();
  }
// Put each element into matched bucket.
  foreach ($my_array as $el) {
    array_push($buckets[ceil($el/10)], $el);
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
  // This will be $a in comparison function.
  // $key will be the right side element that will be
  // compared against the left sorted elements. For
  // min to max sort, $key should be higher than
  // $elements[0] to $elements[$j] 
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
$test_array = array(3, 0, 2, 5, -1, 4, 1);
echo "Original Array :\n";
echo implode(', ',$test_array );
echo "\nSorted Array :\n";
echo implode(', ',bucket_sort($test_array)). PHP_EOL;
?>
