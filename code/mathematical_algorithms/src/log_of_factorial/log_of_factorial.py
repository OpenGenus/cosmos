from math import *


def log_factorial(n):
    i = 1
    x = 0
    while i <= n:
        x += log10(i)
        i += 1
    return x


print("This program will find the log of factorial of entered number.")
number_input = int(input("enter your number"))
print("log of factorial of", number_input, "is", float(log_factorial(number_input)))
