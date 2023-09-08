def sum_of_digits(n):
    sum = 0
    num_as_string = str(n)
    for c in num_as_string :
        digit = ord(c) - ord('0')
        sum = sum + digit
    return sum

input_text = input()
input_number = int(input_text)
print(sum_of_digits(input_number))
