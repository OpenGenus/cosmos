{-
    Part of Cosmos by OpenGenus Foundation
-}

binarySearch :: [Int] -> Int -> Int -> Int -> Int

binarySearch arr val low high
    | high < low = -1
    | arr!!mid < val = binarySearch arr val (mid+1) high
    | arr!!mid > val = binarySearch arr val low (mid-1)
    | otherwise = mid
    where
        mid = (low + high) `div` 2

main = do
    let arr = [3,5,12,56,92,123,156,190,201,222]

    let number = 12

    putStrLn("Position of "
             ++ show(number)
             ++ " is "
             ++ show(binarySearch arr number 0 ((length arr) - 1)))

