# Part of Cosmos by OpenGenus Foundation
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


n = int(input("Enter a number"))
print("The factorial is " + str(factorial(n)))
