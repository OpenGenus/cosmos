linearsearch :: (Eq a) => [a] -> a -> Maybe Int
linearsearch [] _ = Nothing
linearsearch (x:xs) y = if x == y then Just 0 else (1 +) <$> linearsearch xs y
