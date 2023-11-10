def check_binary(st):

	p = set(st)
	s = {'0', '1'}

	if s==p or p=={'0'} or p=={'1'}:
		return 1
	else:
		return 0

def binary_to_decimal(number):

	i = 0
	output = 0

	while number > 0:

		rem = int(number % 10)
		store = rem * pow(2,i)
		output = output + store
		number = int(number / 10)
		i = i + 1

	return output

numberInput = int(input("Enter the binary number: "))

while check_binary(str(numberInput)) != 1:
	print("Sorry, You entered non binary number")
	numberInput = int(input("Enter the binary number: "))

print(f"{numberInput} in decimal is {binary_to_decimal(numberInput)}")



