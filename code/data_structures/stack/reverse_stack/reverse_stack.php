<?php
// globals variables
define('NEW_LINE','<br>');
$stack = array();

echo "pushing values " . NEW_LINE;
// array_unshift is same as push operation
array_unshift($stack,'1');
array_unshift($stack,'2');
array_unshift($stack,'3');
array_unshift($stack,'4');
array_unshift($stack,'5');

echo NEW_LINE . NEW_LINE . "printing original stack values " . NEW_LINE ;
echo implode(" ",$stack);

echo NEW_LINE . NEW_LINE . "reversing stack values " . NEW_LINE ;
$stack = array_reverse($stack);
echo implode(" ",$stack);

?>
