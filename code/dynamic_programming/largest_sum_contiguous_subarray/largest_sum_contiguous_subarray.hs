module LargestSum where

-- Part of Cosmos by OpenGenus Foundation

sublists [] = []
sublists (a:as) = sublists as ++ [a]:(map (a:) (prefixes as))

suffixes [] = []
suffixes (x:xs) = (x:xs) : suffixes xs

prefixes x = map reverse $ (suffixes . reverse) x

largestSum = maximum . (map sum) . sublists
