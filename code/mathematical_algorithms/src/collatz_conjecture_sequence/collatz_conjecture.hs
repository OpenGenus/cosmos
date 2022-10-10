collatzConjecture :: Int -> [Int]
collatzConjecture 1 = [1]
collatzConjecture n | even n    = n : collatzConjecture (n `div` 2)
                    | otherwise = n : collatzConjecture (3 * n + 1)

main = do
  putStrLn "Choose a number to start the sequence:"
  num <- readLn
  let result = collatzConjecture num
  print result