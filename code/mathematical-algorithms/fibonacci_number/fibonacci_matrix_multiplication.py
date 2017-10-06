"""
Author: sidd607
Email: sidd607@gmail.com

Calculating the nth Fibonacci Number in O(logN) using matrix multiplications

let F(n) be the nth fibonacci number

The matrix representation gives the following closed expression for the Fibonacci numbers
([[1 1],[1 0]])^n = [[F(n+1) F(n)], [F(n) F(n-1)]]

More information at https://kukuruku.co/post/the-nth-fibonacci-number-in-olog-n/

"""

def fibonacci(n):
    """
    Returns the nth Fibonacci number
    F(0) = 0, F(1) = 1 ....

    """
    if n == 0:
        return 0

    F = [[1,1],[1,0]]
    power(F, n-1)
    return F[0][0]

def power(F, n):
    """
    Transforms matrix F to F^n
    """
    if n == 0 or n == 1:
        return

    M = [[1,1],[1,0]]

    power(F, n/2)
    multiply(F, F)

    if n%2 != 0:
        multiply(F, M)

def multiply(F, M):
    """
    Multiplies two matrix F, M
    Stores the result in F

    """

    x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]
    y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]
    z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]
    w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]

    F[0][0] = x
    F[0][1] = y
    F[1][0] = z
    F[1][1] = w

if __name__ == "__main__":

    # Test Case : Printing first 10 Fibonacci numbers
    for i in xrange(10):
        print fibonacci(i)

