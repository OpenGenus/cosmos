# Part of Cosmos by OpenGenus Foundation
def factorial(n):
    '''
    Function to find factorial of any number >= 0
    INPUT: integer num
    OUTPUT: integer factorial of num

    e.g. 4! = 4*3! = 4*3*2! = 4*3*2*1! = 4*3*2*1*1 = 24
    '''

    if n == 0:   # exit condition for recursion
        return 1
    else:
        return n * factorial(n - 1) # recursively call factorial to find factorial of num-1


n = int(input("Enter a number"))
print("The factorial is " + str(factorial(n)))
