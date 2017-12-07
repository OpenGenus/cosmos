-- Part of Cosmos by OpenGenus Foundation
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = let less = filter (<x) xs in
                 let greater = filter (>=x) xs in
                    (quicksort less) ++ [x] ++ (quicksort greater)