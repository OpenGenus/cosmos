-- Part of Cosmos by OpenGenus Foundation
split_list::[a]->([a],[a])
split_list x = splitAt (div (length x) $ 2) x

merge_sort::Ord a=>[a]->[a]
merge_sort x
    | length x == 0 = []
    | length x == 1 = x
    | length x > 1 = merge (merge_sort left) (merge_sort right)
        where (left,right)=split_list x
    


merge::Ord a=>[a]->[a]->[a]
merge [] r = r
merge l [] = l
merge l@(l':ls) r@(r':rs) 
    | l' < r' =  l' : merge ls r
    | otherwise = r' : merge rs l

main =  do
    print $ merge_sort [9,6,4,3,2,1,2,5]
