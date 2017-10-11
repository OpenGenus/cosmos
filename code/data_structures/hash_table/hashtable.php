<?php
// globals variables
define('NEW_LINE','<br>');
$hashtable = array();
// key starting from
$key = 1;

echo "adding  values " . NEW_LINE;
$hashtable[$key++] = "AdiChat";
$hashtable[$key++] = "tbhaxor";
$hashtable[$key++] = "SandySingh";

echo NEW_LINE . NEW_LINE . "printing key : values " . NEW_LINE ;
foreach ($hashtable as $key => $value) {
  echo "$key : $value" . NEW_LINE;
}

echo NEW_LINE . NEW_LINE . "delting 3 rd value " . NEW_LINE ;
unset($hashtable[3]);


echo NEW_LINE . NEW_LINE . "printing key : values " . NEW_LINE ;
foreach ($hashtable as $key => $value) {
  echo "$key : $value" . NEW_LINE;
}
?>
