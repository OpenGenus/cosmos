# Part of Cosmos by OpenGenus Foundation


def integral_rectangle(a, b, step, func):
    fragment = (b - a) / step
    res = step * (func(a) + func(b)) / 6.0
    i = 1
    while i <= fragment:
        res += 4.0 / 6.0 * step * func(a + step * (i - 0.5))
        i += 1
    i = 1
    while i <= fragment - 1:
        res += 2.0 / 6.0 * step * func(a + step * i)
        i += 1
    return res


print("Enter interval: ")
start = float(input("a: "))
finish = float(input("b: "))
move = float(input("Enter integration step: "))
result = integral_rectangle(start, finish, move, lambda x: x ** 2 + x)
print("Result: ", result)
