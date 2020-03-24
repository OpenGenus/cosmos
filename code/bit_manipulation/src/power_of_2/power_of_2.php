<?php
function isPowerOf2($x)
{
     if (($x & ($x - 1)) != 0)
    		return "$x is not power of 2";
     else
        {
    		return "$x is power of 2";
        }
}
print_r(isPowerOf2(32)."\n");
print_r(isPowerOf2(31)."\n");
