calcArmstrong :: Int -> Int
calcArmstrong 0 = 0
calcArmstrong num = rem^3 + calcArmstrong (num `div` 10)
    where rem = num `mod` 10

checkArmstrong :: Int -> Int -> Bool
checkArmstrong i num = i == num

getMessage :: Bool -> String
getMessage True = " is an Armstrong number"
getMessage False = " is not Armstrong number"

main = do
  putStrLn "Enter a three digit integer:"
  num <- readLn
  let result = show num ++ getMessage (checkArmstrong (calcArmstrong num) num)
  print result