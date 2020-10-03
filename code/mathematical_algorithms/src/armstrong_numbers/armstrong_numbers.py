"""
Armstrong Number - In case of an Armstrong number of 3 digits, the sum of 
cubes of each digits is equal to the number itself. 
"""

# Part of Cosmos by OpenGenus Foundation
def Armstrong(num):
    order = len(str(num))
    sum = 0
    temp = num
    while temp > 0:
        digit = temp % 10
        sum = sum + digit ** order
        temp = temp // 10
    if sum == num:
        return True
    else:
        return False


if __name__ == "__main__":
    Armstrong(407)
