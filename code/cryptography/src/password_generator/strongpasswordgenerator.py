# This program will generate a strong password using cryptography principles

# Import secrets and string module
# The string module defines the alphabet, and the secret module generates cryptographically sound random numbers
import secrets
import string

# Define the alphabet to be digits, letters, and special characters
letters = string.ascii_letters
digits = string.digits
special = string.punctuation
alphabet = letters + digits + special

# Set the password length
while True: 
	try:
		password_length = int(input("Please enter the length of your password: "))
		break
	except ValueError: 
		print("Please enter an integer length.")

# Generates strong password with at least one special character and one digit
while True:
	password = ''
	for i in range(password_length):
		password += ''.join(secrets.choice(alphabet))
	if (any(char in special for char in password) and any(char in digits for char in password)):
		break
                          
print("--------Your Password Has Been Generated---------")
print(password)
print("--------Make Sure To Keep Your Password Safe---------")
