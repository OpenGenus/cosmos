# Use random points to calculate PI (Estimate)

## Summary
Given number randow points that x and y coordinations are less than 1 unit.
Find compute PI (estimate)

## Solve
- Let draw a square with size 2 units
- Let draw a circle with radius 1 unit inside the square
- Area of the square = size * size = 2 * 2 = 4
- Area of the circle = Pi * radius * radius = Pi * 1 * 1 = Pi
- x and y uniform random less than 1 so the ratio 
  Area of the circle / Area of the square = number points inside circle / total points
- Known x * x + y * y <= 1 then (x,y) is inside cirle
- Therefore: Pi/4 = number points inside circle / total points

**Pi = 4 * number points inside circle / total points**

### Let write the solution in Python
