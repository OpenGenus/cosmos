#################
#  dynamic programming | digit dp | Python
#  Part of Cosmos by OpenGenus Foundation
#################

# How many numbers x are there in the range a to b?
# where the digit d occurs exactly k times in x?


def digit_dp(n, d, k):
	"""
	Return total numbers less than equal to n having digit d in them k
	times.
	"""

	# dp[pos][count][f] = Number of valid numbers <= b from this state
	# pos = current position from left side (zero based)
	# count = number of times we have placed the digit d so far
	# f = the number we are building has already become smaller
	# than b? [0 = no, 1 = yes]
	dp = [[[-1] * 2 for i in range(k+1)] for i in range(len(str(n)))]

	def digit_dp_helper(num, pos, count, f):
		"""A recursive helper function for digit_dp function."""
		if count > k:
			return 0

		if pos == len(num):
			return count == k

		if dp[pos][count][f] != -1:
			return dp[pos][count][f]

		result = 0
		limit = 0

		if f == 0:
			# Digits we placed so far matches with the prefix of b
			# So if we place any digit > num[pos] in the current position, then
			# the number will become greater than b
			limit = int(num[pos]) - 0
		else:
			# The number has already become smaller than b.
			# We can place any digit now.
			limit = 9

		# Try to place all the valid digits such that the number doesn't
		# exceed b
		for dgt in range(limit+1):
			fNext = f
			countNext = count

			# The number is getting smaller at this position
			if f == 0 and dgt < limit:
				fNext = 1

			if dgt == d:
				countNext += 1

			if countNext <= k:
				result += digit_dp_helper(num, pos + 1, countNext, fNext)

		dp[pos][count][f] = result
		return dp[pos][count][f]

	return digit_dp_helper(str(n), 0, 0, 0)


def main():
	"""Main function."""
	a = 100
	b = 100000000
	d = 3
	k = 5
	ans = digit_dp(b, d, k) - digit_dp(a-1, d, k)
	print(ans)


if __name__ == "__main__":
	main()
