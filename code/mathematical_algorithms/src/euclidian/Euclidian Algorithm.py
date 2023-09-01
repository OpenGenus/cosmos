#Euclidean Algorithm:
"""
In mathematics, the Euclidean algorithm,[note 1] or Euclid's algorithm, is an efficient method for computing the greatest common divisor (GCD)
of two integers (numbers), the largest number that divides them both without a remainder.
"""

#Implementation:
def euclideanAlgorithm(p,q):
    while p != q:
        if p > q:
            p = p-q
        else:
            q = q-p
    return(p,q)

#Test Cases:
print(euclideanAlgorithm(20, 19))
print(euclideanAlgorithm(27, 22))
print(euclideanAlgorithm(38, 18))
print(euclideanAlgorithm(13, 9))
print(euclideanAlgorithm(7, 3))

