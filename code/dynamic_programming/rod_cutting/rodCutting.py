def rodCutting(res, prices, n):
	if(n==1):
		res[1] = prices[1]
	else:
		# call recursively
		rodCutting(res, prices, n-1)		
		maxval = prices[n]
		for i in xrange(1, n):
			maxval = max(maxval, prices[i] + res[n-i])
		res[n] = maxval


n = input("Enter value of n: ")
res = [-1]*(n+1)
prices = [-1]*(n+1)
for i in xrange(n):
	prices[i+1] = input("")

rodCutting(res, prices, n)

print("Max. amount by cutting rods is: %d"%res[n])
