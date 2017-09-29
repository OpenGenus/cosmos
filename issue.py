op=['+','-','*','/']
a=input("Enter operand")
b=float(input("Enter number1"))
c=float(input("Enter number2"))
if a=='+':
	print(b+c)
elif a=='-':
	print(b-c)
elif a=='*':
	print(b*c)
else:
	print(b/c)