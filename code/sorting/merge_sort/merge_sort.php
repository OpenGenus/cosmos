<?php

$array = array(0,1,6,7,6,3,4,2);

function merge_sort($array)
{
    if(count($array) == 1 )
    {
        return $array;
    }

    $mid = count($array) / 2;
    $left = array_slice($array, 0, $mid);
    $right = array_slice($array, $mid);
    $left = merge_sort($left);
    $right = merge_sort($right);

    return merge($left, $right);
}


function merge($left, $right)
{
    $res = array();
    while (count($left) > 0 && count($right) > 0)
    {
        if($left[0] > $right[0])
        {
            $res[] = $right[0];
            $right = array_slice($right , 1);
        }
        else
        {
            $res[] = $left[0];
            $left = array_slice($left, 1);
        }
    }
    while (count($left) > 0)
    {
        $res[] = $left[0];
        $left = array_slice($left, 1);
    }
    while (count($right) > 0)
    {
        $res[] = $right[0];
        $right = array_slice($right, 1);
    }
    return $res;
}

print 'unsorted array';
echo "\n";
print_r($array);
print 'sorted array';
echo "\n";
print_r(merge_sort($array));


?>
