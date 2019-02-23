# Python program to generate odd sized magic squares
# A function to generate odd sized magic squares


def generateSquare(n):

    # 2-D array with all slots set to 0
    magicSquare = [[0 for x in range(n)] for y in range(n)]

    # initialize position of 1
    i = n / 2
    j = n - 1

    # Fill the magic square by placing values
    num = 1
    while num <= (n * n):
        if i == -1 and j == n:  # third condition
            j = n - 2
            i = 0
        else:
            # next number goes out of right side of square
            if j == n:
                j = 0
            # next number goes out of upper side
            if i < 0:
                i = n - 1

        if magicSquare[i][j]:  # 2nd condition
            j = j - 2
            i = i + 1
            continue
        else:
            magicSquare[i][j] = num
            num = num + 1

        j = j + 1
        i = i - 1  # 1st condition

    # Printing magic square

    print("Magic Squre for n = ", n)
    print("Sum of each row or column", n * (n * n + 1) / 2)

    for i in range(0, n):
        for j in range(0, n):

            print("%2d " % (magicSquare[i][j]), end=" ")
        print()


# Driver program

# Works only when n is odd
n = 7
generateSquare(n)
