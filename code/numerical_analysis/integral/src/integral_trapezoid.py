# Part of Cosmos by OpenGenus Foundation


def integral_trapezoid(a, b, step, func):
    fragment = (b - a) / step
    res = step * (func(a) + func(b)) / 2.0
    i = 1
    while i <= fragment - 1:
        res = res + step * func(a + step * i)
        i += 1
    return res


print("Enter interval: ")
start = float(input("a: "))
finish = float(input("b: "))
move = float(input("Enter integration step: "))
result = integral_trapezoid(start, finish, move, lambda x: x ** 2 + x)
print("Result: ", result)
