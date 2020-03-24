<?php
function is_Power($x)
{


 if (($x & ($x - 1)) != 0)
		return "$x is not power of 2";
 else
    {
		return "$x is power of 2";
    }

}

print_r(is_Power(32)."\n");
print_r(is_Power(31)."\n");
?>
