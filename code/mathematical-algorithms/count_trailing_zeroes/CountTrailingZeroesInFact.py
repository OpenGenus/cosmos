# Part of Cosmos by OpenGenus Foundation

def FunctionforCalculatingThePowerOF5(n):
	count=0
	i=5
	while(n//i>=1):
		count+=n//i
		i*=5
	return count

print(FunctionforCalculatingThePowerOF5(100))
