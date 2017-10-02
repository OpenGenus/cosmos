operators=['+','-','*','/','**','%']
a=input("Enter operand")
b=float(input("Enter number1"))
c=float(input("Enter number2"))
if a=='+':
	print(b+c)
elif a=='-':
	print(b-c)
elif a=='*':
	print(b*c)
elif a=='/':
	if c == 0:
		print("Division by zero not allowed")
	else:
		print(b/c)

elif a=='%':
	if c == 0:
		print("Modulo by zero not allowed")
	else:
		print(b%c)

elif a=='**':
	print(b**c)
else:
	print("Invalid operation")
