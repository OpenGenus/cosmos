{-
	Part of Cosmos by OpenGenus Foundation	
-}

insertion_sort :: Ord a => [a] -> [a]

insertion_sort [] = []
insertion_sort [x] = [x]

insertion_sort (x:arrx) = insert $ insertion_sort arrx
    where insert [] = [x]
          insert (y:arry)
              | x < y = x : y : arry
              | otherwise = y : insert arry


main = do
	let arr = [3,5,12,56,92,123,156,190,201,222]
	putStrLn("Sorted Array: "
	         ++ show(insertion_sort(arr)))
