import os

num = int(input("Enter a number: "))
os.system("tput setaf 3")

exponent = int(input("Enter the Exponent Value: "))
os.system("tput setaf 5")

power = 1

for i in range(1, exponent+1):
	power *= num

print(f"{num} to the power of {exponent} = {power}")