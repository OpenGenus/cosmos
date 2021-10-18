def minSkips(self, A, s, target):
    n = len(A)
    dp = [0] * (n + 1)
    for i, a in enumerate(A):
        for j in range(n, -1, -1):
            dp[j] += a
            if i < n - 1:
                dp[j] = (dp[j] + s - 1) / s * s
            if j:
                dp[j] = min(dp[j], dp[j - 1] + a)
    for i in range(n):
        if dp[i] <= s * target:
            return i
    return -1
if __name__ == '__main__':
#Input: dist = [1, 3, 2], speed = 4, hoursBefore = 2
#Output: 1
#Explanation:
#Without skipping any rests, you will arrive in (1/4 + 3/4) + (3/4 + 1/4) + (2/4) = 2.5 hours.
#You can skip the first rest to arrive in ((1/4 + 0) + (3/4 + 0)) + (2/4) = 1.5 hours.
#Note that the second rest is shortened because you finish traveling the second road at an integer 
# #hour due to skipping the first rest.
    dist1 = [1, 3, 2]
    speed1 = 4
    hoursBefore1 = 2
    print(minSkips(minSkips,dist1,speed1,hoursBefore1)-1)#returns 1
#Input: dist = [7, 3, 5, 5], speed = 2, hoursBefore = 10
#Output: 2
#Explanation:
#Without skipping any rests, you will arrive in (7/2 + 1/2) + (3/2 + 1/2) + (5/2 + 1/2) + (5/2) = 11.5 hours.
#You can skip the first and third rest to arrive in ((7/2 + 0) + (3/2 + 0)) + ((5/2 + 0) + (5/2)) = 10 hours.  
    dist2 = [7, 3, 5, 5]
    speed2 = 2
    hoursBefore2 = 10
    print(minSkips(minSkips, dist2, speed2, hoursBefore2)-1)#returns 2
#Input: dist = [7, 3, 5, 5], speed = 1, hoursBefore = 10
#Output: -1
#Explanation: It is impossible to arrive at the meeting on time even if you skip all the rests.
    dist3 = [7, 3, 5, 5]
    speed3 = 1
    hoursBefore3 = 10
    print(minSkips(minSkips, dist3, speed3, hoursBefore3))
