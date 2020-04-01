"""
  Part of Cosmos by OpenGenus Foundation
 
  Description:
   1. We will start with inputing the number of row n and column m.
   2. We will make memorization table dp table for storing precomputed values and fill that matrix with -1
   3. We will create function getCount(), which have parameter i represent index along row , j represent index along col, 
 	   n represent size of row, m represent size of columns and dp[0..n][0..m] used to store the precomputed value	   
   4. We take a top-down approach, first filling dp[0..n][0..m] = -1
   5. Now, for each (i, j, n, m) we will start moving recuesively along row and column, till we find destination
      
      Case 1: If we reach the destination or out of the box, we will return 1, which represent 
              that their is possible way present to reach destination in maze.
   6. We get the formula: dp[i][j] = getCount(i+1, j, n, m, dp) + getCount(i, j+1, n, m, dp)
 						we will return value, If it is present in the dp[0..n][0..m] 
                         
   7. We will pass function in decorator and store the data using dp table and return that value when needed
 
"""
def memoize(getCount):
    dp = [[-1] * 1000]*1000
    def helper(i,j,n,m):
        if dp[i][j] not in dp:            
            dp[i][j] = getCount(i,j,n,m)
        return dp[i][j]
    return helper

def getCount(i,j,n,m):
    #we exit the condition 
    if(i==n-1 or j==m-1):
        return 1
    
    return getCount(i+1,j,n,m)+getCount(i,j+1,n,m)

getCount = memoize(getCount)

if __name__ == "__main__":
    print("Enter maze")
    row = int(input("Enter row: "))
    col = int(input("Enter column: "))
    path = getCount(0,0,row,col)
    print("the number of ways to : ",path)
