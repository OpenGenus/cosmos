module MinimumCoins where                                                               
                                                                                        
-- Part of Cosmos by OpenGenus                                                          
                                                                                        
safeHead [] = Nothing                                                                   
safeHead (x:xs) = Just x                                                                
                                                                                        
-- takes denominations in decreasing order                                              
-- returns valid solution if such exists                                                
minCoins :: Int -> [Int] -> Maybe [Int]                                                 
minCoins 0 _ = Just []                                                                  
minCoins n denominations =                                                              
  let                                                                                   
    next = safeHead $ filter (<= n) denominations                                       
  in                                                                                    
    next >>= \x -> (x:) <$> minCoins (n - x) denominations                              
                                                                                        
usDenom = [50, 25, 10, 5, 1]                                                            
                                                                                        
-- simple test                                                                          
main = print $ minCoins 77 usDenom == Just [50, 25, 1, 1] 
