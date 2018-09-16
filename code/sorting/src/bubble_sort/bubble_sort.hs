-- Part of Cosmos by OpenGenus Foundation
bubblesort :: (Ord a) => [a] -> [a]
bubblesort [] = []
bubblesort [x] = [x]
bubblesort (x:y:ys) = let (z:zs) = bubblesort (y:ys) in
                        if x < z then x:z:zs else bubblesort (z:x:zs)