# Part of Cosmos by OpenGenus Foundation


def factorial_iteration(num):
    result = 1
    while num != 0:
        result *= num
        num -= 1

    return result


n = int(input("Enter a number"))
print("The factorial is ", factorial_iteration(n))
