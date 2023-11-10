#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue May 29 13:36:32 2018

@author: Sahit
"""

import numpy as np


def Correction(matrix_1, matrix_2):
    r = max(matrix_1.shape[0], matrix_1.shape[1], matrix_2.shape[0], matrix_2.shape[1])
    i = 1
    while i < r:
        i = i * 2

    return i
    """
    result = np.zeros((i,i))
    for i in xrange(matrix.shape[0]):
        for j in xrange(matrix.shape[1]):
            result[i][j] = matrix[i][j]
    return result
    """


def Modification(matrix, p):
    result = np.zeros((p, p))
    for i in range(matrix.shape[0]):
        for j in range(matrix.shape[1]):
            result[i][j] = matrix[i][j]
    return result


def Extraction(matrix, x, y):
    result = np.zeros((x, y))
    for i in range(x):
        for j in range(y):
            result[i][j] = matrix[i][j]

    return result


def Strassen(matrix_1, matrix_2):
    r = matrix_1.shape[0] // 2
    if r == 0:
        return matrix_1.dot(matrix_2)
    else:

        a = matrix_1[:r, :r]
        b = matrix_1[:r, r:]
        c = matrix_1[r:, :r]
        d = matrix_1[r:, r:]

        e = matrix_2[:r, :r]
        f = matrix_2[:r, r:]
        g = matrix_2[r:, :r]
        h = matrix_2[r:, r:]

        p1 = Strassen(a, f - h)
        p2 = Strassen(a + b, h)
        p3 = Strassen(c + d, e)
        p4 = Strassen(d, g - e)
        p5 = Strassen(a + d, e + h)
        p6 = Strassen(b - d, g + h)
        p7 = Strassen(a - c, e + f)

        s1 = p5 + p4 + p6 - p2
        s2 = p1 + p2
        s3 = p3 + p4
        s4 = p1 + p5 - p3 - p7

        result = np.zeros((r * 2, r * 2))

        for i in range(r):
            for j in range(r):
                result[i][j] = s1[i][j]

        for i in range(r):
            for j in range(r):
                result[i][r + j] = s2[i][j]

        for i in range(r):
            for j in range(r):
                result[r + i][j] = s3[i][j]

        for i in range(r):
            for j in range(r):
                result[r + i][r + j] = s4[i][j]

        return result


print("enter the dimensions of the first matrix")
r1 = list(map(int, input().split()))
x1, y1 = r1[0], r1[1]
print("enter the dimensions of the second matrix")
r2 = list(map(int, input().split()))
x2, y2 = r2[0], r2[1]


m1 = []
for i in range(x1):
    row = []
    for j in range(y1):
        print("enter the ", i + 1, j + 1, " element of the first matrix")
        row.append(input())
    m1.append(row)

m2 = []
for i in range(x2):
    row = []
    for j in range(y2):
        print("enter the ", i + 1, j + 1, " element of the second matrix")
        row.append(input())
    m2.append(row)


matrix1 = np.array(m1)
matrix2 = np.array(m2)

f = Correction(matrix1, matrix2)

answer = Extraction(
    Strassen(Modification(matrix1, f), Modification(matrix2, f)), x1, y2
)
print(answer)
