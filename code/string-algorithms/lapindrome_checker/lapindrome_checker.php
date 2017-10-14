<?php
// use apache server to view

// some variable and assignments
$text = "lol";   // demo string
$length = strlen($text); // getting the
$mid = intval($length / 2);  // divinding and converting float to int
$iter = ($length % 2) == 0 ? $mid : $mid + 1;  // if length is even -> iter = length/2    else iter = (length/2) + 1

// applying algo and printing the answer
$left_slice = substr($text,0,$mid);  // slicing from first char to mid
$right_slice = substr($text,$iter,$length); // if odd then ignoring middle

// making string to array in order to sort them
$left_slice_to_array = str_split($left_slice);
$right_slice_to_array = str_split($right_slice);

// sorting arrays
sort($left_slice_to_array);
sort($right_slice_to_array);

// assigning back sorted array to slice strings
$left_slice = implode("",$left_slice_to_array);
$right_slice = implode("",$right_slice_to_array);

// if left_slice is same as right_slice then the string is palindrome
if($left_slice == $right_slice)
  echo "LAPINDROME";
else
  echo "NOT A LAPINDROME";
?>
