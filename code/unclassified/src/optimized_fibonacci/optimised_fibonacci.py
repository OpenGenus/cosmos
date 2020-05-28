# this function returns nth Fibonacci number.
def fib(n): 
	if (n == 0): return 0

	F = [[1, 1], [1, 0]] 
	power(F, n - 1) 
		
	return F[0][0] 
	
def multiply(F, M): 
	
	m00 = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) 
	m01 = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) 
	m10 = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) 
	m11 = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) 
	
	F[0][0] = m00 
	F[0][1] = m01 
	F[1][0] = m10 
	F[1][1] = m11 
		
        
def power(F, n): 
	if(n==0 or n==1): return 

	M = [[1, 1], [1, 0]] 
	power(F, n // 2) 
	multiply(F, F) 
		
	if (n % 2 != 0): multiply(F, M) 

n = 29
print(fib(n)) 

# https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/