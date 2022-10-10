squareRoot :: Double -> Double -> Double
squareRoot num guess    | abs (guess * guess - num) > 0.0000001 = squareRoot num ((guess + (num / guess)) / 2)
                        | otherwise = guess

main = do
  putStr "Enter number for finding square root: "
  num <- getLine
  let result = squareRoot (read num) (read num / 2)
  putStr ("The square root of " ++ num ++ " is ")
  print result