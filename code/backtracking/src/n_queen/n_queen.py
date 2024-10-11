# Part of Cosmos by OpenGenus Foundation
def place(k, i):   # checking the queen placement in k th row and i th column.
    for l in range(1, k):  
        if (x[l] == i) or (abs(x[l] - i) == abs(l - k)): # checking the same column and same diagnal of the queens
            return False                                 
    return True                 #  queens have distinct columns and diagonals


def nqueens(k):  
    global x, n, flag

    for j in range(1, n + 1):  # iterate over all columns
        if place(k, j):        # k queen's column is valid or not
            x[k] = j           # assign the column for k queen
            if k == n:         # if all the queens checked and following all the constraints then print them
                print(x[1 : n + 1])
                flag = 1           # at least one solution exist
            else:
                nqueens(k + 1)  # calling function again for next queen 


def main():
    global n, x, flag
    flag = 0
    n = input("Enter n for n-queen problem solution:")  # number of queens
    x = [i for i in range(n + 1)]                       # list of queens from 1 to n
    for m in range(1, n + 1):
        print("\nFirst queen is placed in column:", m, "\n")
        x[1] = m                                        # assign the m th column for 1 queen 
        nqueens(2)                                      # calling the recursive function with 2 queen
        if flag == 0:                                   # if no solution found i.e. no placement is valid for n queen there
            print("No solution exists for queen placed in column:", m)
        print("\n")


if __name__ == "__main__":
    main()
