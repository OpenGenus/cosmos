# Part of Cosmos by OpenGenus Foundation
def count_set_bit(number):
    count = 0

    while number:
        count = count + (number & 1)
        number = number >> 1

    return count


print(count_set_bit(9))
