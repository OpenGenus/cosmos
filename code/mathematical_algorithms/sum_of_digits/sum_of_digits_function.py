#Part of Cosmos by OpenGenus Foundation
def sum_of_digits(number):
    # converts the number into a string which is further converted into an array of numbers using map and 
    # sum function calculating the sum of numbers in the list
    return sum(map(int, str(number)))

input_text = input("Input your digits: ") # python3 - default input format is string

input_number = int(input_text.strip())
print("Sum of your digits is: {0}".format(sum_of_digits(input_number)))
