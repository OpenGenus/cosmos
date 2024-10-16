import math

print("Find (x, y) solutions for 1/x + 1/y=1/n")
# Input N
n = int(input("Enter a positive integer (n):"))
# Smallest y
y = n+1
# Calculate x 
x = (n*y)/(y-n)
# loop to find solutions
while (x>=y):
    # x is a position integer, then a solution is found
    if (x.is_integer()):
        x_int = math.floor(x)
        print(f"(x={x_int},y={y}) solution for 1/{n} = 1/{x_int}+1/{y}")
    # new y
    y += 1
    # new x
    x = (n*y)/(y-n)

