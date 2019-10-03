import random

# Part of Cosmos by OpenGenus Foundation


def integral_monte_carlo(a, b, point_count, func):
    rand_y = 0.0
    i = 0
    while i < point_count:
        rand_x = (b - a) * random.random() + a
        rand_y += func(rand_x)
        i += 1
    res = (b - a) * (rand_y / point_count)
    return res


print("Enter interval: ")
start = float(input("a: "))
finish = float(input("b: "))
count = float(input("Enter point count: "))
result = integral_monte_carlo(start, finish, count, lambda x: x ** 2 + x)
print("Result: ", result)
