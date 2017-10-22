quicksort :: (Ord a) => [a] -> [a]
quicksort []        = []
quicksort (x:xs)    = smaller ++ [x] ++ larger
    where   smaller = quicksort $ filter (<=x) xs
            larger  = quicksort $ filter (>x) xs
