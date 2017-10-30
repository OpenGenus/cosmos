#Part of Cosmos by OpenGenus Foundation
def sum_of_digits(number):
    return sum(map(int, str(number)))
    
try:
    input_text = raw_input("Input your digits: ") # python2
except NameError:
    input_text = input("Input your digits: ") # python3
               
input_number = int(input_text.strip())
print("Sum of your digits is: {0}".format(sum_of_digits(input_number)))
