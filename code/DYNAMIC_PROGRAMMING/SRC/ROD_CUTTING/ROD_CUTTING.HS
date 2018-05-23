import Data.Array
rodCutting :: Int -> [Int] -> Int
-- Part of Cosmos by OpenGenus Foundation
-- NOTE: great article on lazy DP http://jelv.is/blog/Lazy-Dynamic-Programming/
rodCutting x priceList | x < 0 = 0
               | otherwise = r!x
               where priceArray = listArray (0, length priceList) priceList -- for faster indexing into prices
                     r = listArray (0,x) (0: map f [1..x])
                     f k = maximum [priceArray!(i-1) + rodCutting (k-i) priceList | i <- [1..k]]
