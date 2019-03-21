#!/usr/bin/python3


def greatest_digit(n):
    max_digit = int(n % 10)

    while n:
        if max_digit < n % 10:
            max_digit = n % 10
        else:
            max_digit = max_digit
        n /= 10
    return max_digit


def greatest_digits_with_builtins(num):
    return int(max([*str(num)]))


user_number = int(input("enter number: "))
print("greatest digit is :\n", int(greatest_digit(user_number)))
print("greatest digit is :\n", greatest_digits_with_builtins(user_number))
