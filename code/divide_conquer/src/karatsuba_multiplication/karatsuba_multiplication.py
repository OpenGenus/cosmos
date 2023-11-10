#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue May 29 11:21:34 2018

@author: Sahit
"""


print("enter the first number")
n1 = input()
print("enter the second number")
n2 = input()


def Correcting(string):
    p = len(string)
    i = 1
    while i < p:
        i = i * 2
    return i


l = max(Correcting(n1), Correcting(n2))
num1 = "0" * (l - len(n1)) + n1
num2 = "0" * (l - len(n2)) + n2


def Karatsuba(number_1, number_2):
    l = len(number_1)
    r1 = int(number_1)
    r2 = int(number_2)
    if len(number_1) == 1:
        return r1 * r2
    else:
        a = number_1[: l // 2]
        b = number_1[l // 2 :]
        c = number_2[: l // 2]
        d = number_2[l // 2 :]

        e = Karatsuba(a, c)
        f = Karatsuba(b, d)
        g = Karatsuba(b, c)
        h = Karatsuba(a, d)

        return ((10 ** l) * e) + (g + h) * (10 ** (l / 2)) + f


ans = Karatsuba(num1, num2)
print(ans)
