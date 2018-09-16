-- Part of Cosmos by OpenGenus Foundation
hanoi :: Int -> String -> String -> String -> IO Int
hanoi 0 _ _ _ = return 0
hanoi x from to using = do
  c1 <- hanoi (x-1) from using to
  putStrLn ("Moving " ++ show x ++ " from " ++ from ++ " to " ++ to)
  c2 <- hanoi (x-1) using to from
  return (1+ c1 + c2)
