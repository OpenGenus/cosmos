<?php
function shell_Sort($my_array)
{
	$x = round(count($my_array)/2);
	while($x > 0)
	{
		for($i = $x; $i < count($my_array);$i++){
			$temp = $my_array[$i];
			$j = $i;
			while($j >= $x && $my_array[$j-$x] > $temp)
			{
				$my_array[$j] = $my_array[$j - $x];
				$j -= $x;
			}
			$my_array[$j] = $temp;
		}
		$x = round($x/2.2);
	}
	return $my_array;
}
 
$test_array = array(3, 0, 2, 5, -1, 4, 1);
echo "Original Array :\n";
echo implode(', ',$test_array );
echo "\nSorted Array\n:";
echo implode(', ',shell_Sort($test_array)). PHP_EOL;
?>