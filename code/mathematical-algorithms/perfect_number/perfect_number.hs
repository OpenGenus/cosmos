--Perfect Number
module PerfectNumber where

perfectNum :: Integer -> Bool
perfectNum n = factorSum n == n

factorSum :: Integer -> Integer
factorSum n = sum [x | x <- [1..n], mod n x == 0, x < n]

perfectList = map perfectNum [1..]