import Data.Maybe (listToMaybe)

type Board = [Int]

nQueens :: Int -> Maybe Board
nQueens = listToMaybe . nQueens'

nQueens' :: Int -> [Board]
nQueens' n = go n []
  where
    go 0 bs = [bs]
    go k bs = concatMap (go (k - 1)) [ x : bs | x <- [1..n], placeable x bs]

    placeable n xs = null [ i | (i,x) <- zip [1..] xs, n == x || abs (n - x) == i]

