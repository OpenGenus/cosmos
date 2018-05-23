<?php
//recursive function to calculate factorial of a number
// Part of Cosmos by OpenGenus Foundation
function factorial($number) {          
        if ($number < 2) { 
            return 1; 
        } else { 
            return ($number * factorial($number-1)); 
        } 
    }
?>
