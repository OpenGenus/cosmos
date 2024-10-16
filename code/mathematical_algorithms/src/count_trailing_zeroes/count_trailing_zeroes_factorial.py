# Part of Cosmos by OpenGenus Foundation
def findTrailingZeroes(n):
    count = 0
    i = 5
    while n // i >= 1:
        count = count + n // i
        i = i * 5
    return count


n = int(input("Enter the number:"))
print("You entered " + str(n))
print("The number of trailing zeroes = " + str(findTrailingZeroes(n)))
