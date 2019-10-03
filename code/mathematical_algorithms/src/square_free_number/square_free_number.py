# Program to check whether a number is square_free or not
from math import sqrt


def is_square_free(n):

    if n % 2 == 0:
        n = n / 2

    if n % 2 == 0:
        return False

    for i in range(3, int(sqrt(n) + 1)):

        if n % i == 0:
            n = n / i
            if n % i == 0:
                return False

    return True


n = int(input("Enter a number "))
if is_square_free(n):
    print(str(n) + " is square free number")
else:
    print(str(n) + " is not a square free number")
