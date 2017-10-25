# Matrix chain multiplication
Matrix chain multiplication is an optimization problem that can be solved using dynamic programming. Given a sequence of matrices, the goal is to find the most efficient way to multiply these matrices. The problem is not actually to perform the multiplications, but merely to decide the sequence of the matrix multiplications involved.

Here are many options because matrix multiplication is associative. In other words, no matter how the product is parenthesized, the result obtained will remain the same. For example, for four matrices A, B, C, and D, we would have:

((AB)C)D = ((A(BC))D) = (AB)(CD) = A((BC)D) = A(B(CD)).
However, the order in which the product is parenthesized affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, if A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix, then

computing (AB)C needs (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations, while
computing A(BC) needs (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.

To begin, let us assume that all we really want to know is the minimum cost, or minimum number of arithmetic operations needed to multiply out the matrices. If we are only multiplying two matrices, there is only one way to multiply them, so the minimum cost is the cost of doing this. In general, we can find the minimum cost using the following recursive algorithm:

Take the sequence of matrices and separate it into two subsequences.
Find the minimum cost of multiplying out each subsequence.
Add these costs together, and add in the cost of multiplying the two result matrices.
Do this for each possible position at which the sequence of matrices can be split, and take the minimum over all of them.
For example, if we have four matrices ABCD, we compute the cost required to find each of (A)(BCD), (AB)(CD), and (ABC)(D), making recursive calls to find the minimum cost to compute ABC, AB, CD, and BCD. We then choose the best one. Better still, this yields not only the minimum cost, but also demonstrates the best way of doing the multiplication: group it the way that yields the lowest total cost, and do the same for each factor.

# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter

Collaborative effort by [OpenGenus](https://github.com/opengenus)
