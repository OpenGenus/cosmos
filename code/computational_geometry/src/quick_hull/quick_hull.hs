-- Part of Cosmos by OpenGenus
-- Point in 2-D plane
data Point = Point {
                  x::Double,
                  y::Double
             }
           deriving (Show)

instance Eq Point where
  (==) (Point x1 y1) (Point x2 y2)  = x1 == x2 && y1 == y2

instance Ord Point where
  compare (Point x1 y1) (Point x2 y2)  = compare x1 x2
  (<=) (Point x1 y1) (Point x2 y2) = x1 <= x2

pplus :: Point -> Point -> Point
pplus (Point x1 y1) (Point x2 y2)  = Point (x1+x2) (y1+y2)

pminus :: Point -> Point -> Point
pminus (Point x1 y1) (Point x2 y2)  = Point (x1-x2) (y1-y2)

-- Compute the dot product AB ⋅ BC
dot :: Point -> Point -> Double -- we use point type to represent vectors
dot (Point ab1 ab2) (Point bc1 bc2) = ab1 * bc1 + ab2 * bc2

-- Compute the cross product AB x AC
 -- we use point type to represent vectors
cross :: Point -> Point -> Double -- 2 dimensional so return scalar
cross (Point ab1 ab2) (Point ac1 ac2)  = ab1 * ac2 - ab2 * ac1

distance :: Point -> Point -> Double
distance (Point a1 a2) (Point b1 b2) = sqrt (d1*d1+d2*d2)
  where d1 = a1 - b1
        d2 = a2 - b2

quickHull :: [Point] -> [Point]
quickHull [] = []
quickHull l = trace ("A: " ++ show pA ++ " and B: " ++ show pB ++ "\n") $ pA : pB : findHull rhs pA pB ++ findHull lhs pB pA
  where (lhs, rhs) = partition l pA pB
        pA = maximum l
        pB = minimum l

partition :: [Point] -> Point -> Point -> ([Point], [Point])
-- returns ([points on LHS of line AB], [points on RHS of line AB])
partition l pA pB = (partition' (\x -> snd x > 0) , partition' (\x -> snd x < 0))
  where pointOPMap = zip l (map _ABCrossAP l)
        _ABCrossAP p = (pB `pminus` pA) `cross` (p `pminus` pA)
        partition' f = map fst (filter f pointOPMap)

-- Triangle PQM looks like this:
--          M
--          ·
--        ·  ·
--   S2 ·     ·  S1
--    ·    S0  ·
--  ·           ·
-- · · · · · · · ·
-- Q             P
findHull :: [Point] -> Point -> Point -> [Point]
findHull [] _ _  = []
findHull s p q   = trace ("M: " ++ show m ++ " P: " ++ show p ++ "Q: " ++ show q ++ "\n") $ m : findHull s1 p m ++ findHull s2 m q
  where m        = s!!fromJust (elemIndex max_dist dists) -- point of maximum distance on RHS of PQ
        max_dist = maximum dists
        dists    = map (linePointDist p q) s
        s1       = snd $ partition s p m -- rhs of line PM (outside triangle)
        s2       = fst $ partition s q m -- lhs of line QM (outside triangle)


-- Compute the distance from line segment AB to C
linePointDist :: Point -> Point -> Point -> Double
linePointDist a b c | dot1 > 0  = distbc
                    | dot2 > 0  = distac
                    | otherwise = abs dist
  where dot1   = dot (c `pminus` b) (b `pminus` a)
        dot2   = dot (c `pminus` a) (a `pminus` b)
        distbc = distance b c
        distac = distance a c
        dist   = cross (b `pminus` a) (c `pminus` a) / distance a b
