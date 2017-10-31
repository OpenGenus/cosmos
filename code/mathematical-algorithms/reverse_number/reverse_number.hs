reverseInt :: Integer -> Integer
reverseInt x | x < 0     = 0 - (read . reverse . tail . show $ x)
             | otherwise = read . reverse . show $ x
