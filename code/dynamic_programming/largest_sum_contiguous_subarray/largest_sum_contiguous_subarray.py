# Part of Cosmos by OpenGenus Foundation

# Function to find the maximum contiguous subarray using Kadane's algorithm
def maxSubArraySum(a,size):

    max_so_far = a[0] 
    max_ending_here = max(a[0], 0)

    for i in range(1, size):
        max_ending_here += a[i]
        max_so_far = max(max_so_far, max_ending_here)
        max_ending_here = max(max_ending_here, 0);

    return max_so_far

# Enter the number seperated by spaces
arr = [int(x) for x in input().split()]

print("Maximum contiguous sum is", maxSubArraySum(arr,len(arr)))
