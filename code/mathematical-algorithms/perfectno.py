#Part of Cosmos by OpenGenus Foundation
import math

def primefactorisationMultiplication(n):
	arr=[]
	for i in range(1,int(math.sqrt(n))+1):
		if n%i==0:
			a=n//i;b=i
			
			if a!=b:
				arr.append(n//i)
				arr.append(i)
			else:
				arr.append(i)
				
	return (sum(arr)-n)	
n=int(input("enter the no till which u want to get the perfect Nos\n"))		
for i in range(1,n):
	if primefactorisationMultiplication(i)==i:
		print(i)
			
	        
