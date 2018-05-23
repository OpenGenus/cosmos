module Radix where
import Data.List
import Data.Bits

-- Part of Cosmos by OpenGenus Foundation

-- intoBuckets separates the input list into two lists, one where a bit
-- is set, and one where the bit is not set.
intoBuckets' odds evens bit [] = (reverse odds, reverse evens)
intoBuckets' odds evens bit (x:xs)
  | x `testBit` bit =                intoBuckets' (x:odds) evens bit xs
intoBuckets' odds evens bit (x:xs) = intoBuckets' odds (x:evens) bit xs

intoBuckets :: (Num a, Integral a, Bits a) => Int -> [a] -> ([a], [a])
intoBuckets = intoBuckets' [] []

-- radix' sorts by each binary digit from 0 to max
radix' 0 _ list = list
radix' n max list = radix' (n - 1) max $ lows ++ highs
  where
    (highs, lows) = intoBuckets (max - n) list

-- radix simply calculates the number of passes required for a full
-- run of radix sort, and then applies radix' that many times.
radix :: (Num a, Ord a, Integral a, Bits a) => [a] -> [a]
radix list = radix' (m) m list
  where
    m = floor ((log (fromIntegral (foldl max 0 list)) / log 2) + 1)

-- Here's a testcase:

test :: [Integer]
test = [539, 581, 943, 94, 189, 928, 481, 343, 487, 34, 230, 775, 524, 97, 347, 357, 109, 935, 542, 298, 943, 921, 696, 306, 727, 995, 148, 413, 986, 154, 934, 495, 664, 33, 484, 808, 770, 976, 705, 52, 521, 909, 491, 530, 466, 741, 121, 321, 174, 851, 639, 418, 589, 721, 982, 131, 91, 741, 268, 10, 432, 171, 14, 919, 807, 57, 201, 973, 638, 279, 526, 656, 867, 332, 45, 567, 505, 349, 898, 239, 151, 317, 397, 91, 400, 456, 260, 352, 649, 438, 627, 789, 748, 440, 416, 823, 61, 71, 693, 559]

testSorted = [10, 14, 33, 34, 45, 52, 57, 61, 71, 91, 91, 94, 97, 109, 121, 131, 148, 151, 154, 171, 174, 189, 201, 230, 239, 260, 268, 279, 298, 306, 317, 321, 332, 343, 347, 349, 352, 357, 397, 400, 413, 416, 418, 432, 438, 440, 456, 466, 481, 484, 487, 491, 495, 505, 521, 524, 526, 530, 539, 542, 559, 567, 581, 589, 627, 638, 639, 649, 656, 664, 693, 696, 705, 721, 727, 741, 741, 748, 770, 775, 789, 807, 808, 823, 851, 867, 898, 909, 919, 921, 928, 934, 935, 943, 943, 973, 976, 982, 986, 995]

-- A very simple test driver
main = print (radix test == testSorted)
