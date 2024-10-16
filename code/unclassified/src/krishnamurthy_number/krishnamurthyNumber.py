# helper function
def factorial(n):
    fact = 1
    while n != 0:
        fact *= n
        n -= 1
    return fact


def checkKrishnamurthy(n):
    sumOfDigits = 0   # will hold sum of FACTORIAL of digits
    temp = n

    while temp != 0:

        # get the factorial of of the last digit of n and add it to sumOfDigits
        sumOfDigits += factorial(temp % 10)

        # replace value of temp by temp/10
        # i.e. will remove the last digit from temp
        temp //= 10

    # returns True if number is krishnamurthy
    return (sumOfDigits == n)


if __name__ == '__main__':
    n = 40585   # input number
    print(checkKrishnamurthy(40585))
