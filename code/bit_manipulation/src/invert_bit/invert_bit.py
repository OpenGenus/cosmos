# Part of Cosmos by OpenGenus Foundation


def invert_bit(digit, number_bit):
    digit ^= 1 << number_bit
    return digit


number = int(input("Enter numeric: "))
num_bit = int(input("Enter number bit: "))
res = invert_bit(number, num_bit)
print(res)
