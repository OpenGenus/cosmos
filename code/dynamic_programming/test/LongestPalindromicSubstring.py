    def longestPalindrome(self, s):
        n = len(s)
        dp = [[False for i in range(n)] for j in range(n)]
        ans = ''
        maxlen = 0
        
        #Strings of length 1
        for i in range(n):
            dp[i][i] = True
            ans = s[i]
            maxlen = 1
        
        #Strings of length 2
        for i in range(n-1):
            if s[i] == s[i+1]:
                maxlen = 2
                ans = s[i:i+2]
                dp[i][i+1] = True
        
        #Strings of length > 2
        for j in range(n):
            for i in range(j-1):
                if s[i]==s[j] and dp[i+1][j-1] is True:
                    dp[i][j] = True
                    if maxlen < j-i+1:
                        maxlen = max(maxlen, j-i+1)
                        ans = s[i:j+1]
                    
        
        return ans
