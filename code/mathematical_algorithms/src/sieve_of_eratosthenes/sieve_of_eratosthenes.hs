module Eratosthenes where

-- Part of Cosmos by OpenGenus Foundation

eratosthenes :: [Integer] -- A list of all prime numbers
eratosthenes = go [2..]
  where
    -- If we have something in the front of the list (x:xs),
    -- we know it wasn't filtered, so it's prime.
    -- Then, we filter the rest of the list to exclude multiples of
    -- that number.
    go (x:xs) = x : (go $ filter (\n -> n `mod` x /= 0) xs)

primes = eratosthenes

main = do
  n <- getLine
  print $ take (read n :: Int) primes
