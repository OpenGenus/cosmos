# Part of Cosmos by OpenGenus Foundation
def lcs(X , Y):
	m = len(X)
	n = len(Y)
	dp = [[0]*(n+1) for i in range(m+1)]
	for i in range(m+1):
		for j in range(n+1):
			if i == 0 or j == 0 :
				dp[i][j] = 0
			elif X[i-1] == Y[j-1]:
				dp[i][j] = dp[i-1][j-1]+1
			else:
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1])
	return dp[m][n]


X = "FABCDGH"
Y = "AVBDC"
#ABC is the longest common subsequence
print "Length of LCS = ", lcs(X, Y)
