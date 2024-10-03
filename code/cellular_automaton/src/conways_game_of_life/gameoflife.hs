{-# LANGUAGE DeriveFunctor #-}

module GameOfLife where

import Control.Comonad
import Graphics.Gloss
import Data.List
import Control.Monad
import System.Random

data Zipper a = Zipper [a] a Int [a] deriving (Functor)
  -- Zipper ls x n rs represents the doubly-infinite list (reverse ls ++
  -- [x] ++ rs) viewed at offset n
instance (Show a) => Show (Zipper a) where
  show (Zipper ls x n rs) =
    show (reverse (take 3 ls)) ++ " " ++ show (x,n) ++ " " ++ show (take 3 rs)

instance Comonad Zipper
  where
    extract (Zipper _ x _ _)  = x
    duplicate z = Zipper (tail $ iterate back z) z 0 (tail $ iterate forth z)

back, forth :: Zipper a -> Zipper a
back (Zipper (l:ls) x n rs)  = Zipper ls l (n-1) (x:rs)
forth (Zipper ls x n (r:rs)) = Zipper (x:ls) r (n+1) rs

newtype Grid a = Grid (Zipper (Zipper a)) deriving (Functor)
instance Show a => Show (Grid a) where
  show (Grid (Zipper ls x n rs)) =
    unlines $ zipWith (\a b -> a ++ " " ++ b)
              (map show [n-3..n+3])
              (map show (reverse (take 3 ls) ++ [x] ++ (take 3 rs)))

instance Comonad Grid
  where
    extract = get
    duplicate (Grid z) = fmap Grid $ Grid $ roll $ roll z
      where
        roll g = Zipper (tail $ iterate (fmap back) g) g 0 (tail $ iterate (fmap forth) g)

up, down, right, left :: Grid a -> Grid a
up (Grid g) = Grid (back g)
down (Grid g) = Grid (forth g)
left (Grid g) = Grid (fmap back g)
right (Grid g) = Grid (fmap forth g)

set :: a -> Grid a -> Grid a
set y (Grid (Zipper ls row n rs)) = (Grid (Zipper ls (set' row) n rs))
  where set' (Zipper ls' x m rs') = Zipper ls' y m rs'

get :: Grid a -> a
get (Grid (Zipper _ (Zipper _ x _ _) _ _)) = x

resetH :: Grid a -> Grid a
resetH g@(Grid (Zipper _ (Zipper _ _ m _) n _))
  | m > 0 = resetH (left g)
  | m < 0 = resetH (right g)
  | otherwise = g

resetV :: Grid a -> Grid a
resetV g@(Grid (Zipper _ (Zipper _ _ m _) n _))
  | n > 0 = resetV (up g)
  | n < 0 = resetV (down g)
  | otherwise = g

recenter :: Grid a -> Grid a
recenter = resetH . resetV

falseGrid :: Grid Bool
falseGrid =
  let falseRow = Zipper falses False 0 falses
      falses = repeat False
      falseRows = repeat falseRow
  in  Grid (Zipper falseRows falseRow 0 falseRows)

copyBox :: [[a]] -> Grid a -> Grid a
copyBox [] g = recenter g
copyBox (xs:xss) g = copyBox xss (down $ copyArray xs g)
  where
  copyArray [] g = resetH g
  copyArray (x:xs) g = copyArray xs (right $ set x g)

extractBox :: Int -> Int -> Grid a -> [[a]]
extractBox m n (Grid g) = map (f n) $ (f m) g
  where
    f m (Zipper _ x _ xs) = x : take (m - 1) xs

liveNeighborCount :: Grid Bool -> Int
liveNeighborCount grid = length . filter (True == ) $ map (\direction -> get $ direction grid) directions
  where
    directions = [left, right, up, down, up . left, up . right, down . left, down . right]

stepCell :: Grid Bool -> Bool
stepCell grid
  | cell == True && numNeighbors < 2    = False
  | cell == True && numNeighbors < 4    = True
  | cell == True && numNeighbors > 3    = False
  | cell == False && numNeighbors == 3  = True
  | otherwise                           = cell
  where
    cell = extract grid
    numNeighbors = liveNeighborCount grid

makeRandomGrid :: Int -> Int -> IO (Grid Bool)
makeRandomGrid m n = do
            bools <- (replicateM m $ replicateM n (randomIO :: IO Bool))
            return $ copyBox bools falseGrid

toPicture :: Int -> Int -> Grid Bool -> Picture
toPicture m n grid =
  let bools = extractBox m n grid
      (width, height) = (fromIntegral m , fromIntegral n)
      indexed = map (zip [0.. ] . sequence) . zip [0..]
      cell = rectangleSolid 10 10
      draw (x, (y, s)) = color (if s then black else white) . translate ((x-width/2)*10+5) ((y-height/2)*10+5)
    in pictures . map (pictures . map (\s -> draw s cell)) . indexed $ bools

main :: IO ()
main = do
  grid <- makeRandomGrid 100 100
  simulate FullScreen blue 1 grid (toPicture 100 100) (const $ const (=>> stepCell))
