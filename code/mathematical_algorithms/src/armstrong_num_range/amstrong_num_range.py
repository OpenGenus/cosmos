sum_pow = 0.0

#Accept the lower and upper range from the user
lower = int(input("Enter lower range: "))
upper = int(input("Enter upper range: "))

print(f"Armstrong numbers between {lower} and {upper} are: ")

for i in range(lower,upper+1):

	temp1 = i
	temp2 = i

	#calculate number of digits
	num = len(str(temp1))

	#calculate sum of nth power of its digits
	while temp2 != 0:
		rem = int(temp2 % 10)
		sum_pow = sum_pow + pow(rem,num)
		temp2 = int(temp2 / 10)

	#check if it is an Armstrong number
	if int(sum_pow) == i:
		print(i)

	sum_pow = 0.0
