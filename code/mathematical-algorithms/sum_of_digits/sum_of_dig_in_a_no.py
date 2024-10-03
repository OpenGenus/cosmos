# Part of Cosmos by OpenGenus Foundation

def sum_dig_InaNum(num):
	sum=0
	while(num!=0):
		x=num%10
		sum+=x
		num//=10
	return sum		
print(sum_dig_InaNum(111))
