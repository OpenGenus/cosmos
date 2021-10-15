def minPalPartion(str):
	
	# Get the length of the string
	n = len(str)
	
	# Create two arrays to build the
	# solution in bottom up manner
	# C[i][j] = Minimum number of cuts
	# needed for palindrome
	# partitioning of substring str[i..j]
	# P[i][j] = true if substring str[i..j]
	# is palindrome, else false. Note that
	# C[i][j] is 0 if P[i][j] is true
	C = [[0 for i in range(n)]
			for i in range(n)]
	P = [[False for i in range(n)]
				for i in range(n)]

	# different looping variables
	j = 0
	k = 0
	L = 0
	
	# Every substring of length
	# 1 is a palindrome
	for i in range(n):
		P[i][i] = True;
		C[i][i] = 0;
		
	# L is substring length. Build the
	# solution in bottom-up manner by
	# considering all substrings of
	# length starting from 2 to n.
	# The loop structure is the same as
	# Matrix Chain Multiplication problem
	# (See https://www.geeksforgeeks.org / matrix-chain-multiplication-dp-8/ )
	for L in range(2, n + 1):
		
		# For substring of length L, set
		# different possible starting indexes
		for i in range(n - L + 1):
			j = i + L - 1 # Set ending index
			
			# If L is 2, then we just need to
			# compare two characters. Else
			# need to check two corner characters
			# and value of P[i + 1][j-1]
			if L == 2:
				P[i][j] = (str[i] == str[j])
			else:
				P[i][j] = ((str[i] == str[j]) and
							P[i + 1][j - 1])
							
			# IF str[i..j] is palindrome,
			# then C[i][j] is 0
			if P[i][j] == True:
				C[i][j] = 0
			else:
				
				# Make a cut at every possible
				# location starting from i to j,
				# and get the minimum cost cut.
				C[i][j] = 100000000
				for k in range(i, j):
					C[i][j] = min (C[i][j], C[i][k] +
								C[k + 1][j] + 1)
									
	# Return the min cut value for
	# complete string. i.e., str[0..n-1]
	return C[0][n - 1]

# Driver code
str = "ababbbabbababa"
print ('Min cuts needed for Palindrome Partitioning is',
									minPalPartion(str))
									
