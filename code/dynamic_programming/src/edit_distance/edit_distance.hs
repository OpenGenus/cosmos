--- dynamic programming | edit distance | Haskell
--- Part of Cosmos by OpenGenus
--- Adapted from http://jelv.is/blog/Lazy-Dynamic-Programming/ 

module EditDistance where
import Data.Array

editDistance :: String -> String -> Int
editDistance a b = d m n
  where (m, n) = (length a, length b)
        a' = listArray (1, m) a -- 1-indexed to simplify arithmetic below
        b' = listArray (1, n) b
        d i 0 = i
        d 0 j = j
        d i j
          | a' ! i ==  b' ! j = table ! (i - 1, j - 1)
          | otherwise = minimum [ table ! (i - 1, j)     + 1
                                , table ! (i, j - 1)     + 1
                                , table ! (i - 1, j - 1) + 1
                                ]
        table = listArray bounds
               [d i j | (i, j) <- range bounds] -- 2D array to store intermediate results
        bounds = ((0, 0), (m, n))

main = print $ editDistance "sunday" "saturday" == 3
