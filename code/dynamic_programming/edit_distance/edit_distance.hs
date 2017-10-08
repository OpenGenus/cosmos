module EditDistance where

-- Part of Cosmos by OpenGenus

editDistance [] a = length a -- Must insert remaining
editDistance a [] = length a
editDistance (a:as) (b:bs) | a == b = editDistance as bs -- No change neeed
editDistance (a:as) (b:bs) = 1 + foldl min (editDistance (a:as) bs) [editDistance as (b:bs), editDistance as bs] -- Find minimum recursivly.


main = print $ editDistance "sunday" "saturday" == 3
