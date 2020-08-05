# Recursive function to calculate catalan numbers
def catalanNum(n):
    # Base case
    if n <= 1:
        return 1

    #Initialize result of a catalan number to 0
    result = 0

    # Catalan(n + 1) = summation of Catalan(i) * Catalan(n - i) for all i from 0 to n
    for i in range(n):
        result += catalanNum(i) * catalanNum(n - i - 1)
    return result

# Driver function to print first 15 catalan numbers
for i in range(15):
    print(catalanNum(i))
