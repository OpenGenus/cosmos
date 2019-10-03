#!/usr/bin/python3


def smallest_digit(n):
    min_digit = int(n % 10)

    while n != 0:
        if min_digit > n % 10:
            min_digit = n % 10

        n //= 10
        print(int(min_digit))
    return min_digit


user_number = int(input("enter number: "))
print("smallest digit is :\n", int(smallest_digit(user_number)))
