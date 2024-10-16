def DelannoyGenerator(n,m):
	if n==0 or m==0:
		d = 1
	else:
		d = DelannoyGenerator(n-1,m) + DelannoyGenerator(n,m-1) + DelannoyGenerator(n-1,m-1)

	return d

n = int(input("Provide the 'n' value: "))
m = int(input("Provide the 'm' value: "))

print(f"The delannoy number is: {DelannoyGenerator(n,m)}")	