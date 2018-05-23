<?php
// Author: Napat R.
// Github: @peam1234

/* Checker */
function checkPalindrome($input) {
  return $input === strrev($input);
}

/* Tests */
echo checkPalindrome('rotator').'<br>'; // should return true
echo checkPalindrome('stats').'<br>'; // should return true
echo checkPalindrome('morning').'<br>'; // should return false
?>