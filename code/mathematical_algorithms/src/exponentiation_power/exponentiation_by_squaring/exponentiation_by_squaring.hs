-- | Part of Cosmos by OpenGenus Foundation

-- module nill where

import Numeric (showIntAtBase)
import Data.Char (intToDigit)
import Data.Maybe()


-- | Square & Multiply Algorithm
-- | input values: base and expn
-- | return value: base^expn
exp_by_sqr :: Int -> Int -> Int
exp_by_sqr base expn
  | (expn == 0) = 1
  | (expn == 1 || base == 0 || base == 1) = base
  | otherwise = exp_by_sqr_rec base (tail $ showIntAtBase 2 intToDigit expn "") 0
  where
    exp_by_sqr_rec :: Int -> [Char] -> Int -> Int
    exp_by_sqr_rec _ [] rv = rv
    exp_by_sqr_rec base_n bin_exp rv =
      let
        rva = if (rv == 0) then (base_n * base_n) else (rv * rv)  -- always square
        rvb = if head bin_exp == '1' then base_n * rva else rva   -- sometimes multiply
      in (exp_by_sqr_rec base_n (tail bin_exp) rvb)


main :: IO ()
main = do
  putStrLn "Enter a base: "
  base <- getLine
  putStrLn "Enter a expn: "
  expn <- getLine
  putStrLn "result: base^expn"
  print $ exp_by_sqr (read base :: Int) (read expn :: Int)
