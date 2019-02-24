# Part of Cosmos by OpenGenus Foundation
def sum_of_digits(number):
    return sum(map(int, str(number)))


input_text = int(input("Input your digits: "))
print("Sum of your digits is: {0}".format(sum_of_digits(input_number)))
