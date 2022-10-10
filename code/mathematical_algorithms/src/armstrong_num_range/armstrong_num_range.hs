armstrongList :: Int -> Int -> [Int]
armstrongList lower upper | lower == upper = []
                          | checkArmstrong lower (sumPow lower (div10 lower 0)) = lower : armstrongList (lower + 1) upper
                          | otherwise = armstrongList (lower + 1) upper
                                
div10 :: Int -> Int -> Int
div10 0 num = num
div10 i num = div10 (i `div` 10) (num + 1)

sumPow :: Int -> Int -> Int
sumPow 0 num = 0
sumPow i num = (i `mod` 10) ^ num + sumPow (i `div` 10) num

checkArmstrong :: Int -> Int -> Bool
checkArmstrong i num = i == num

main = do
  print "Enter lower range: "
  lower <- getLine
  print "Enter upper range: "
  upper <- getLine
  let result = armstrongList (read lower) (read upper)
  print result