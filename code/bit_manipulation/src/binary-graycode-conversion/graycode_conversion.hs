-- Binary to Gray
binaryToGray :: Int -> Int
binaryToGray n = n `xor` (n `shiftR` 1)

-- Gray to Binary
grayToBinary :: Int -> Int
grayToBinary 0 = 0
grayToBinary g = foldl xor 0 (takeWhile (>0) (iterate (`shiftR` 1) g))

main :: IO ()
main = do
    let num = 7
    let gray = binaryToGray num
    print ("Gray Code: " ++ show gray)  -- Output: 4
    print ("Binary Code: " ++ show (grayToBinary gray)) -- Output: 7
