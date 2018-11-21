from math import sqrt

# Tests whether the given integer is a prime number.
def is_prime(x):
	if x <= 1:
		return False
	elif x <= 3:
		return True
	elif x % 2 == 0:
		return False
	else:
		for i in range(3, int(sqrt(x)) + 1, 2):
			if x % i == 0:
				return False
		return True

NONPRIME_LAST_DIGITS = set([0, 2, 4, 5, 6, 8])

def compute():
	for i in range(9, 0, -1):
		arr = list(range(i, 0, -1))
		while True:
			if i == 1 or arr[-1] not in NONPRIME_LAST_DIGITS:
				n = int("".join([str(x) for x in arr]))
				if eulerlib.is_prime(n):
					return str(n)
			if not prev_permutation(arr):
				break


def prev_permutation(arr):
	i = len(arr) - 1
	while i > 0 and arr[i - 1] <= arr[i]:
		i -= 1
	if i <= 0:
		return False
	j = len(arr) - 1
	while arr[j] >= arr[i - 1]:
		j -= 1
	arr[i - 1], arr[j] = arr[j], arr[i - 1]
	arr[i : ] = arr[len(arr) - 1 : i - 1 : -1]
	return True


if __name__ == "__main__":
	print(compute())
