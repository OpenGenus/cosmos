import numpy as np

class Matrix:
    def __init__(self, matrix):
        np.set_printoptions(threshold=np.nan)
        self.matrix = np.matrix(matrix)  # matrix is also an array :P
        pass
    
    def __str__(self):
        return str(self.matrix)
    
    def __add__(self, matrix):
        return self.matrix + matrix.matrix
    
    def __sub__(self, matrix):
        return self.matrix - matrix.matrix
    
    def __mul__(self, matrix):
        return self.matrix * matrix.matrix

    def __eq__(self, matrix):
        return self.matrix == matrix.matrix
    pass

m1 = [[1, 1], [1, 1]]
m2 = [[1, 1], [1, 2]]

A = Matrix(m1)
B = Matrix(m2)

print("-- Addition --")
print(A + B)
print("-- Subtraction --")
print(A - B)
print("-- Multiplication --")
print(A * B)
print("-- Checking Equality --")
print(A == B)

"""

expected output
-- Addition --
[[2 2]
 [2 3]]
-- Subtraction --
[[ 0  0]
 [ 0 -1]]
-- Multiplication --
[[2 3]
 [2 3]]
-- Checking Equality --
[[ True  True]
 [ True False]]
 
 """
 