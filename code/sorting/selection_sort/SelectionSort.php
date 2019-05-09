<?php
// Part of Cosmos by OpenGenus Foundation

function find_min($arr){
	//traverse array
	for($i=0;$i<count($arr)-1;$i++){
		print(" index is ".$i."\n");
		if($arr[$i]>$arr[$i+1]){
			print("arr is ".$arr[$i]." arr2 is ".$arr[$i+1]."\n");
			$temp=$arr[$i+1];
			$arr[$i+1]=$arr[$i];
			$arr[$i]=$temp;
		}
	}
	return $arr;
}



$test = [1, 3, 43, 2, 14, 53, 12, 87, 33];

print_r($test);
function selection_sort($test){
	for($k=0;$k<count($test);$k++){
       		$test=find_min($test);
	}
	print_r($test);
}
selection_sort($test);
