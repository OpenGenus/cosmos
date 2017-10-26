<?php
/**
 * @param int $a
 * @param int $b
 *
 * @return int
 */
function russianPeasant($a, $b)
{
    $res = 0;
    while ($b > 0){
        if($b % 2 == 1){
            $res += $a;
        }
        $a = $a << 1;
        $b = $b >> 1;
    }

    return $res;
}

echo russianPeasant(57,86);