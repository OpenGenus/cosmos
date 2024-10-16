<?php
// function for counting sort
function countingsort(&$Array, $n) {
  $max = 0;
  
  //find largest element in the Array
  for ($i=0; $i<$n; $i++) {  
    if($max < $Array[$i]) {
      $max = $Array[$i];
    } 
  }

  //Create a freq array to store number of occurrences of 
  //each unique elements in the given array 
  for ($i=0; $i<$max+1; $i++) {  
    $freq[$i] = 0;
  } 

  for ($i=0; $i<$n; $i++) {  
    $freq[$Array[$i]]++;
  } 

  //sort the given array using freq array
  for ($i=0, $j=0; $i<=$max; $i++) {  
    while($freq[$i]>0) {
      $Array[$j] = $i;
      $j++;
      $freq[$i]--;
    }
  } 
}

// function to print array
function PrintArray($Array, $n) { 
  for ($i = 0; $i < $n; $i++) 
    echo $Array[$i]." "; 
  echo "\n";
} 

// test the code
$MyArray = array(9, 1, 2, 5, 9, 9, 2, 1, 3, 3);
$n = sizeof($MyArray); 
echo "Original Array\n";
PrintArray($MyArray, $n);

countingsort($MyArray, $n);
echo "\nSorted Array\n";
PrintArray($MyArray, $n);
?>
