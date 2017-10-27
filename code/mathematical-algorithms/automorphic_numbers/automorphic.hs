--Automorphic number
--An automorphic number is a number whose square "ends" in the same digits as the number itself.
--Ex: 5^2 = 25, 6^2 = 36, 76^2 = 5776, 376^2 = 141376
--Compile: ghc --make automorphic.hs -o automorphic
module Main where

--Check number for automorphism  
automorphic :: Integer -> Bool
automorphic n = (==) n $ automParse (n^2) n

--Return last # digit values of number, # determined by second input
automParse :: Integer -> Integer -> Integer
automParse n = mod n . (10 ^) . subtract 1 . numDigits

--Return number of digits in a number
numDigits :: Integer -> Integer
numDigits = (1+) . round . logBase 10 . fromIntegral

--Infinite list of valid automorphic numbers. Beware high indices.
--Ex: take 6 automList = [5,6,76,376,625,9376] 
automList = filter automorphic [1..]

main :: IO ()
main = do
  putStrLn "Enter a number: "
  num <- readLn
  case automorphic num of
    True  -> putStrLn "Number is automorphic."
    False -> putStrLn "Number is not automorphic."

