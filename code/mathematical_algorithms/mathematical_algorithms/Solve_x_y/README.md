# Find (x, y) solutions for 1/x + 1/y=1/n 

## Summary
Find number of possible solution of 1/x + 1/y=1/n 
- Given n is a positive integer
- x,y where x>=y and positive integer

## Solve
- y is a smallest number integer among denominators
- the smallest positive integer of y is y = n+1
- Therefore x = (n*y)/(y-n)

## Example
Given a positive integer (n):5
- (x=30,y=6)  solution for 1/5 = 1/30+1/6
- (x=10,y=10) solution for 1/5 = 1/10+1/10

### Let solve to find all (x, y) solution in Python

