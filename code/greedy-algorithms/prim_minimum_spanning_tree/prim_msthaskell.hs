prim for            = prim' [n] ns [[]]
    where (n:ns)    = nodes for
        es          = edges for
        prim' t [] mst        = mst
        prim' t (r:rs) (x:xs) = let m = minimum[(c,u',v'| u <-t, v <- (r:rs), (u,v,c) <- es]
                    m | m == Nothing    = prim' (r:t) rs ([]:mst)
                      | otherwise       = prim' (v:t) (delete v' r) ((m:x):xs)