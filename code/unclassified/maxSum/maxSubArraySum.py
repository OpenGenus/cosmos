def maxSubArray(self, A):
    """
    :type nums: List[int]
    :rtype: int
    """
    if not A:
        return 0
      
    currSum = maxSum = A[0]
        
    for num in A[1:]:
        currSum = max(num, currSum+num)
        maxSum = max(maxSum, currSum)
            
    return maxSum
