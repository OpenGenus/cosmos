import random

# Part of Cosmos by OpenGenus Foundation


def pi_monte_carlo(point_count):
    circle_points = 0.0
    i = 0
    while i < point_count:
        x = random.random()
        y = random.random()
        if x * x + y * y < 1:
            circle_points += 1
        i += 1
    pi = (circle_points / point_count) * 4
    return pi


count = float(input("Enter point count: "))
res = pi_monte_carlo(count)
print("Pi = ", res)
