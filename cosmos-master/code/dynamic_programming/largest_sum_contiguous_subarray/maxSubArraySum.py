# Function to find the maximum contiguous subarray using Kadane's algorithm
def maxSubArraySum(a,size):

    max_so_far = -9223372036854775806 #negative sys.maxint 
    max_ending_here = 0

    for i in range(0, size):
        max_ending_here = max_ending_here + a[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here

        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far

# Enter the number seperated by spaces
arr = [int(x) for x in input().split()]

print("Maximum contiguous sum is", maxSubArraySum(arr,len(arr)))
