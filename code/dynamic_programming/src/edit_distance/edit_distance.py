# dynamic programming | edit distance | Python
# Part of Cosmos by OpenGenus Foundation

# A top-down DP Python program to find minimum number
# of operations to convert str1 to str2
def editDistance(str1, str2):
    def editDistance(str1, str2, m, n, memo):
        # If first string is empty, the only option is to
        # insert all characters of second string into first
        if m == 0:
            return n

        # If second string is empty, the only option is to
        # remove all characters of first string
        if n == 0:
            return m

        # If this state has already been computed, just return it
        if memo[m][n] > -1:
            return memo[m][n]

        # If last characters of two strings are same, nothing
        # much to do. Ignore last characters and get count for
        # remaining strings.
        if str1[m - 1] == str2[n - 1]:
            memo[m][n] = editDistance(str1, str2, m - 1, n - 1, memo)
            return memo[m][n]

        # If last characters are not same, consider all three
        # operations on last character of first string, recursively
        # compute minimum cost for all three operations and take
        # minimum of three values.
        memo[m][n] = 1 + min(
            editDistance(str1, str2, m, n - 1, memo),  # Insert
            editDistance(str1, str2, m - 1, n, memo),  # Remove
            editDistance(str1, str2, m - 1, n - 1, memo),  # Replace
        )
        return memo[m][n]

    size = max(len(str1), len(str2)) + 1
    memo = [[-1 for _ in range(size)] for _ in range(size)]
    return editDistance(str1, str2, len(str1), len(str2), memo)


# Driver program to test the above function
str1 = "sunday"
str2 = "saturday"
print(editDistance(str1, str2))
