def isPowerOf2(num):
	return ((num & (num-1))==0) and (num != 0)

try:
	input = raw_input
except NameError:
	pass

n = int(input("Enter a number: "))

if isPowerOf2(n):
	print("Power of 2 spotted!")
else:
	print("Not a power of 2")