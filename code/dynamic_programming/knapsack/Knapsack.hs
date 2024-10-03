module Knapsack (knapsack) where



-- simple (brute-force) version
knapsack :: [Int] -> [Int] -> Int -> Int
knapsack [] _  _ = 0
knapsack _  _  0 = 0
knapsack (w:ws) (v:vs) capacity =
  if w > capacity then
    knapsack ws vs capacity
  else
    max
       (v + knapsack ws vs (capacity - w))
       (knapsack ws vs capacity)

-- to test run
-- knapsack [10, 20, 30] [60, 100, 120] 50 