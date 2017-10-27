-- Part of Cosmos by OpenGenus Foundation
import System.Environment
import Data.List (sort) -- using sort as the internal bucket sorting algorithm

flatten :: [[a]] -> [a]
flatten xs = (\z n -> foldr (\x y -> foldr z y x) n xs) (:) []

bucketSort :: (RealFrac a, Ord a) => [a] -> Integer -> [a]
bucketSort [] _ = []
bucketSort array bucketSize = flatten $ map sort buckets
                              where
                                buckets = [filter (\x -> (getBucketIdx x arMin bucketSize) == i) array | i <- [0..nBuckets]]
                                nBuckets = (floor (arMax - arMin)) `div` bucketSize + 1
                                arMax = maximum array
                                arMin = minimum array

getBucketIdx :: (RealFrac a) => a -> a -> Integer -> Integer
getBucketIdx _   _   0        = error "num buckets is 0?!"
getBucketIdx num min bucketSize = (floor (num - min)) `div` bucketSize

main :: IO ()
main = getArgs >>= \args -> print $ bucketSort (map (\x-> read x :: Float) (tail args)) (read (head args) :: Integer)
