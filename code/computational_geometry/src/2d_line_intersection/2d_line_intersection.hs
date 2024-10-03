-- computational geometry | 2D line intersecton | Haskell
-- line2dintersection.hs
-- @author Sidharth Mishra
-- @description 2 dimensional line intersection program in Haskell
-- @copyright 2017 Sidharth Mishra
-- @created Fri Oct 13 2017 20:42:25 GMT-0700 (PDT)
-- @last-modified Fri Oct 13 2017 20:43:52 GMT-0700 (PDT)
--

module Lines (
  Line(..),
  Point,
  getIntersectionPoint,
  convertToSlopeIntercept,
  getLineFromPoints
) where

-- Line can be represented in the following ways
-- SlopeIntercept (y = mx + c)
-- GeneralForm (ax + by = c)
-- XAxis (y = c)
-- YAxis (x = c)
data Line = SlopeIntercept { 
                slope :: Double,
                intercept :: Double
              } 
            | GeneralForm {
                xcoef :: Double,
                ycoef :: Double,
                constant :: Double
              }
            | XAxis {
                yintercept :: Double
              }
            | YAxis {
                xintercept :: Double
              }
            deriving (Show)


-- Point in 2-D plane
data Point = Point {
                  x::Double, 
                  y::Double
             }
           deriving (Show)


convertToSlopeIntercept :: Line -> Line
-- converts the line from General form to Slope Intercept form
-- XAxis and YAxis and lines parallel to the axes remain unchanged
convertToSlopeIntercept l1 = case l1 of
  (GeneralForm a b c) -> SlopeIntercept {
    slope = (-1) * (a/b),
    intercept = c/b
  }
  (SlopeIntercept s i) -> SlopeIntercept {
    slope = s,
    intercept = i
  }
  (YAxis c) -> YAxis c
  (XAxis c) -> SlopeIntercept {
    slope = 0,
    intercept = c
  }

getIntersectionPoint :: Line -> Line -> Maybe Point
-- Finds the intersection point of the 2 lines
-- first, convert each line into slope-intercept form,
-- then, if m1 == m2, lines are parallel -- return Nothing
-- otherwise, finds the intersection point
getIntersectionPoint l1 l2 = getIntersectionPoint' (convertToSlopeIntercept l1) (convertToSlopeIntercept l2)

getIntersectionPoint' :: Line -> Line -> Maybe Point
-- function for internal usage
--  y = m1x + c1 :: Line #1
--  y = m2x + c2 :: Line #2
-- --------------
-- x = (c2 - c1) / (m1 - m2)
-- y = (m1(c2 - c1) / (m1 - m2)) + c1
getIntersectionPoint' (SlopeIntercept m c) (YAxis c') = getIntersectionPoint' (YAxis c') (SlopeIntercept m c)
getIntersectionPoint' (YAxis c') (SlopeIntercept m c) =
  -- intersection between YAxis and the line -- x = c', y = (m*c' + c)
  return Point {
    x = c',
    y = (m * c') + c
  }
getIntersectionPoint' (SlopeIntercept m1 c1) (SlopeIntercept m2 c2) = 
  if m1 == m2 
  then 
    Nothing -- lines are parallel
  else
    return Point {
      x = (c2 - c1) / (m1 - m2),
      y = (m1 * (c2 - c1) / (m1 - m2)) + c1
    }
getIntersectionPoint' _ _ = Nothing -- catch all condition, this should not be possible though

getLineFromPoints :: Point -> Point -> Line
-- creates a line in slope intercept form from the given 2 points
-- (x1,y1) ------ (x2,y2)
-- given the line is of form  y = mx + b
-- slope = m = (y1 - y2) / (x1 - x2)
-- intercept = b = y1 - (m * x1)
getLineFromPoints (Point x1 y1) (Point x2 y2)
    | x1 == x2 = YAxis { xintercept = x1 } -- m = Infinity
    | y1 == y2 = XAxis { yintercept = y1 } -- m = 0
    | otherwise = SlopeIntercept {
          slope = m,
          intercept = b
      }
    where m = (y1 - y2) / (x1 - x2) 
          b = y1 - (m * x1)


-- For testing, Testing harness
line1 :: Line
-- example line :: y = 0.7x -4
line1 = getLineFromPoints (Point 10 3) (Point 20 10)

line2 :: Line
-- example line :: y = -0.7x + 17
line2 = getLineFromPoints (Point 10 10) (Point 20 3)

line3 :: Line
-- example line :: y = x + 3
line3 = SlopeIntercept { slope = 1, intercept = 3 }

line4 :: Line
-- example line :: y = x + 4
line4 = SlopeIntercept { slope = 1, intercept = 4 }

line5 :: Line
-- example line :: y = 0 -- X Axis
line5 = SlopeIntercept { slope = 0, intercept = 0 }

line6 :: Line
-- example line :: x = 1 -- Y Axis
line6 = getLineFromPoints (Point 1 5) (Point 1 8)

testIntersection :: Line -> Line -> String
-- for testing intersection of 2 lines
testIntersection l1 l2 = "Intersection point:: " ++ case getIntersectionPoint l1 l2 of
  Nothing -> "None, Lines are parallel"
  Just i -> show i

main :: IO()
-- main driver for testing logic
{-  Sample output
    *Lines Data.Maybe> main
    Line1:: SlopeIntercept {slope = 0.7, intercept = -4.0}
    Line2:: SlopeIntercept {slope = -0.7, intercept = 17.0}
    Line3:: SlopeIntercept {slope = 1.0, intercept = 3.0}
    Line4:: SlopeIntercept {slope = 1.0, intercept = 4.0}
    Line5:: SlopeIntercept {slope = 0.0, intercept = 0.0}
    Line6:: YAxis {xintercept = 1.0}
    Line1 & Line2:: Intersection point:: Point {x = 15.000000000000002, y = 6.5}
    Line2 & Line3:: Intersection point:: Point {x = 8.23529411764706, y = 11.235294117647058}
    Line3 & Line4:: Intersection point:: None, Lines are parallel
    Line1 & Line4:: Intersection point:: Point {x = -26.666666666666664, y = -22.666666666666664}
    Line1 & Line3:: Intersection point:: Point {x = -23.33333333333333, y = -20.33333333333333}
    Line2 & Line4:: Intersection point:: Point {x = 7.647058823529412, y = 11.647058823529413}
    Line2 & Line5:: Intersection point:: Point {x = 24.28571428571429, y = 0.0}
    Line5 & Line6:: Intersection point:: Point {x = 1.0, y = 0.0}
    Line6 & Line5:: Intersection point:: Point {x = 1.0, y = 0.0}
    *Lines Data.Maybe>
-}
main = do
  putStrLn $ "Line1:: " ++ show line1
  putStrLn $ "Line2:: " ++ show line2
  putStrLn $ "Line3:: " ++ show line3
  putStrLn $ "Line4:: " ++ show line4
  putStrLn $ "Line5:: " ++ show line5
  putStrLn $ "Line6:: " ++ show line6
  putStrLn $ "Line1 & Line2:: " ++ testIntersection line1 line2
  putStrLn $ "Line2 & Line3:: " ++ testIntersection line2 line3
  putStrLn $ "Line3 & Line4:: " ++ testIntersection line3 line4
  putStrLn $ "Line1 & Line4:: " ++ testIntersection line1 line4
  putStrLn $ "Line1 & Line3:: " ++ testIntersection line1 line3
  putStrLn $ "Line2 & Line4:: " ++ testIntersection line2 line4
  putStrLn $ "Line2 & Line5:: " ++ testIntersection line2 line5
  putStrLn $ "Line5 & Line6:: " ++ testIntersection line5 line6
  putStrLn $ "Line6 & Line5:: " ++ testIntersection line6 line5
