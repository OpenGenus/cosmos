-- Part of Cosmos by OpenGenus Foundation

selectionsort :: (Ord a) => [a] -> [a]
selectionsort [] = []
selectionsort l = let Just (m, i) = minIndex l in
    m:selectionsort (take i l ++ drop (i+1) l)

minIndex :: (Ord a) => [a] -> Maybe (a, Int)
minIndex [] = Nothing
minIndex (x:xs) = case minIndex xs of
    Nothing -> Just (x, 0)
    Just (m, i) -> Just (if x < m then (x, 0) else (m, i+1))
