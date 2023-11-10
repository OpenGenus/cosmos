<?php
// dynamic programming | edit distance | PHP
// Part of Cosmos by OpenGenus Foundation

function editDistance($str1, $str2)
{
    $lenStr1 = strlen($str1);
    $lenStr2 = strlen($str2);

    if ($lenStr1 == 0) {
        return $lenStr2;
    }

    if ($lenStr2 == 0) {
        return $lenStr1;
    }

    $distanceVectorInit = [];
    $distanceVectorFinal = [];

    for ($i = 0; $i < $lenStr1 + 1; $i++) {
        $distanceVectorInit[$i] = $i;
        $distanceVectorFinal[] = 0;
    }

    for ($i = 0; $i < $lenStr2; $i++) {
        $distanceVectorFinal[0] = $i + 1;
        // use formula to fill in the rest of the row
        for ($j = 0; $j < $lenStr1; $j++) {
            $substitutionCost = 0;
            if ($str1[$j] == $str2[$i]) {
                $substitutionCost = $distanceVectorInit[$j];
            } else {
                $substitutionCost = $distanceVectorInit[$j] + 1;
            }

            $distanceVectorFinal[$j+1] = min($distanceVectorInit[$j+1] + 1, min($distanceVectorFinal[$j] + 1, $substitutionCost));
        }

        $distanceVectorInit = $distanceVectorFinal;
    }

    
    return $distanceVectorFinal[$lenStr1];
}

echo editDistance("hello", "hallo");
