
def SieveOfEratosthenes(n): 
	
	isPrime = [True for i in range(n+1)] 
	a = 2
	while (a * a <= n): 
		if (isPrime[a] == True): 
			for i in range(a * a, n+1, a): 
				isPrime[i] = False
		a = a+1
	
	for a in range(2, n+1): 
		if isPrime[a]: 
			print a 

if __name__=='__main__': 
	n = 47
	print("List of Primes until "+str(n)+":")
	SieveOfEratosthenes(n) 

