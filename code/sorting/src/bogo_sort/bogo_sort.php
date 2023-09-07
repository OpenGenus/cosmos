<?php
function issorted($list)
{
    $cnt = count($list);
    for($j = 1; $j < $cnt; $j++)
    {
        if($list[$j-1] > $list[$j])
		{
                return false;
        }
    }
    return true;
}
function bogo_sort($list)
{
    do
    {
        shuffle($list);
    }
    while(!issorted($list));
    return $list;
}
$test_array = array(100, 0, 2, 5, -1, 4, 1);
echo "\nOriginal Array :\n";
echo implode(', ',$test_array );
echo "\nSorted Array :\n";
echo implode(', ',bogo_sort($test_array)). PHP_EOL;
?>
