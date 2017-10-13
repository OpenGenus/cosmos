-- convert_number_binary.hs
--
-- @author Sidharth Mishra
-- @description Program to convert Decimal numbers into Binary numbers
-- @created Thu Oct 12 2017 17:15:23 GMT-0700 (PDT)
-- @last-modified Thu Oct 12 2017 17:15:38 GMT-0700 (PDT)

module NumConv (
  convDecToBin
)

where

-- Binary is used as an type alias for [Char] or String
-- [MSD......LSD]
type Binary = String

notEnoughBits :: String
notEnoughBits = "Need atleast 1 bit to represent the binary nbr :)" 

needMoreBits :: String
needMoreBits = "Needs more bits to convert, partially converted"

negativeNumberNotSupported :: String
negativeNumberNotSupported = "Negative Ints not supported yet"


convDecToBin :: Int -> Int -> Binary
-- Converts a Decimal positive number to its Binary equivalent
-- first param -- number of bits in the Binary number
-- second param -- the decimal number
-- result -- the binary number
convDecToBin 0 _ = notEnoughBits
convDecToBin k n
  | n >= 0 = case convDecToBin' k n "" of 
        Left s -> s
        Right b -> b
  | otherwise = negativeNumberNotSupported

convDecToBin' :: Int -> Int -> Binary -> Either String Binary
-- private helper
convDecToBin' 0 n b
  | n >= 1 = Left needMoreBits
  | otherwise = return b
convDecToBin' k n b = convDecToBin' (k - 1) n' b'
  where n' = n `quot` 2
        r' = n `mod` 2
        b' = show r' ++ b


-- For testing
processInput :: [String] -> Maybe (Int, Int)
-- processes the input from the console/stdin
processInput [] = Nothing
processInput [s] = return (32, read s::Int)
processInput (s:ss) = return (k,n)
  where [k,n] = map (\x -> read x :: Int) (s:ss)

assert :: String -> String -> Bool
-- asserts if expected and actual are equal
assert ex ac = ex == ac

main :: IO()
main = do
    t <- getLine
    let (k,n) = case processInput $ words t of
                    Nothing -> (32,0)
                    Just (x,y) -> (x,y)
        b = convDecToBin k n
    putStrLn $ "\"" ++ b ++ "\""
    print $ assert (convDecToBin 3 3) "011"
    print $ assert (convDecToBin 3 4) "100"
    print $ assert (convDecToBin 32 32) "00000000000000000000000000100000"
    print $ assert (convDecToBin 10 743) "1011100111"
    print $ assert (convDecToBin 2 4) needMoreBits
    print $ assert (convDecToBin 2 (-4)) negativeNumberNotSupported