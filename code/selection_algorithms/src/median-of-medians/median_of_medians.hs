import Data.List

median :: (Show a, Ord a) => [a] -> a
median xs = select ((length xs) `div` 2) xs

select :: (Show a, Ord a) => Int -> [a] -> a
select i xs
  | n <= 5                        = (sort xs) !! i
  | lengthLower == i  = medianOfMedians
  | lengthLower < i   = select (i - lengthLower - 1) upperPartition
  | otherwise         = select i lowerPartition
  where
    n = length xs
    medianOfMedians = median (map median (chunksOf 5 xs))
    (lowerPartition, _:upperPartition) = partition (\x -> x < medianOfMedians) xs
    lengthLower = length lowerPartition
    chunksOf :: Int -> [a] -> [[a]]
    chunksOf _ [] = []
    chunksOf n xs = (take n xs) : (chunksOf n (drop n xs))
