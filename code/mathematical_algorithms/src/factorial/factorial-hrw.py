#!/usr/local/bin/python3.6
# 	This is my way of calculating factorial, i call it the half reverse way, first you divide the number you want it's factorial
# 	then you multiply every number until it's half counting up with every number until it's half counting down then
# 	you multiply all of the multiplication results together and then multiply the result by 2, and there you have it,
# 	a fast fun way to calculate factorial.

from decimal import Decimal

factorial = input("Please give a number to factor: ")
factorial = int(factorial)
sum = 1

halfF = factorial / 2
halfF = int(halfF + 1)
m = (
    []
)  # Here i use an array as a POC to display the results that will be used to calculate factorial
for i in range(1, halfF):
    j = factorial - i
    s = j * i
    m.append(s)
    print(i, "*", j, "=", s)
    sum *= s
sum *= 2
print(sum)
print(m)
