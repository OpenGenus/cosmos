def minSkips(self, A, s, target):
     n = len(A)
      dp = [0] * (n + 1)
       for i, a in enumerate(A):
            for j in xrange(n, -1, -1):
                dp[j] += a
                if i < n - 1:
                    dp[j] = (dp[j] + s - 1) / s * s
                if j:
                    dp[j] = min(dp[j], dp[j - 1] + a)
        for i in xrange(n):
            if dp[i] <= s * target:
                return i
        return -1
