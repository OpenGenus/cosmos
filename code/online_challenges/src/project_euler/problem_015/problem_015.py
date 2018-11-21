# Gives the factorial of a non-negative integer.
def factorial(n):
	assert n >= 0
	result = 1
	for i in range(1, n + 1):
		result *= i
	return result

# Returns the binomial.
def binomial(n, k):
	assert n >= 0 and 0 <= k <= n
	return factorial(n) // (factorial(k) * factorial(n - k))

if __name__ == "__main__":
	print(str(binomial(40, 20)))
