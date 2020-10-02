# Part of Cosmos by OpenGenus Foundation


def factorial_iteration(num):
    '''
    Function to find factorial of any positive number
    INPUT: integer num
    OUTPUT: integer factorial of num

    e.g. 4! = 4*3*2*1 = 24
    '''

    result = 1        # initialize result with 1
    while num != 0:   # loop to multiply all numbers from 1 to num
        result *= num
        num -= 1      # decrement num by 1  

    return result


n = int(input("Enter a number"))
print("The factorial is ", factorial_iteration(n))
