# Part of Cosmos by OpenGenus Foundation

# Recursive function to calculate catalan numbers
def catalan(n):
    # Base case
    if n <= 1:
        return 1

    # Initialize result of a catalan number to 0
    res = 0

    # Catalan(n + 1) = summation of Catalan(i) * Catalan(n - i) for all i from 0 to n
    for i in range(n):
        res += catalan(i) * catalan(n - i - 1)
    return res

# Driver function to print first 10 catalan numbers
for i in range(10):
    print(catalan(i), end=" ")
