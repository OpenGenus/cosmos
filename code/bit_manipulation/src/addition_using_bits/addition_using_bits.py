# Part of Cosmos by OpenGenus Foundation

# Function adds 2 numbers a and b without using + operator
def addition(a, b):
    while b != 0:
        c = a & b  # carry contains set bits of both a and b
        a = a ^ b  # a ^ b is equal to 1 if, the bits of a and b are different
        b = c << 1  # carry is right-shifted by 1
    return a


# Driver code
if __name__ == "__main__":
    print(addition(5, 9))
    print(addition(4, 3))
