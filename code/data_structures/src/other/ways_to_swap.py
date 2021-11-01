a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

# 1. USING THIRD VARIABLE

print("Present value of a = "+ str(a) + " b = " + str(b))

temp = a
a = b
b = temp

print("After swapping using third variable: a = "+ str(a) + " b = " + str(b))

#2. USING ADDITION AND SUBTRACTION

print("Present value of a = "+ str(a) + " b = " + str(b))

a = a + b
b = a - b
a = a - b
print("After swapping using addition and subtraction: a = "+ str(a) + " b = " + str(b))

#3. USING MULTIPLICATION AND DIVISON

print("Present value of a = "+ str(a) + " b = " + str(b))

a = a * b
b = a / b
a = a / b
print("After swapping using multiplication and division: a = "+ str(int(a)) + " b = " + str(int(b)))

#4. USING BITWISE XOR OPERATOR

print("Present value of a = "+ str(int(a)) + " b = " + str(int(b)))

a = int(a) ^ int(b)
b = int(a) ^ int(b)
a = a ^ b

print("After swapping using bitwise XOR: a = "+ str(a) + " b = " + str(b))
