# Part of Cosmos by OpenGenus Foundation


def invert_bit(digit, number_bit):
    digit ^= 1 << number_bit
    return digit

digit_ = int(input('Enter numeric: '))
number_bit_ = int(input('Enter number bit: '))
res = invert_bit(digit_, number_bit_)
print(res)