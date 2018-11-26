# Returns the factorial of the given non-negative integer.
def factorial(n):
	assert n >= 0
	result = 1
	for i in range(1, n + 1):
		result *= i
	return result

def binomial(n, k):
	assert n >= 0 and 0 <= k <= n
	return factorial(n) // (factorial(k) * factorial(n - k))

def compute():
	ans = 0
	for n in range(1, 101):
		for k in range(0, n + 1):
			if binomial(n, k) > 1000000:
				ans += 1
	return str(ans)

if __name__ == "__main__":
	print(compute())
