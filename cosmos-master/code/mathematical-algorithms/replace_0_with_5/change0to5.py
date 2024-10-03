# Part of Cosmos by OpenGenus Foundation
n = list(input("Enter the number: "))
for i in range(len(n)):
	if(n[i]=='0'):
		n[i]='5'
print("modified number: "+ ''.join(n))
