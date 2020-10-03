# Part of Cosmos by OpenGenus Foundation

# Function to find the maximum contiguous subarray using Kadane's algorithm
def maxSubArraySum(a):

    max_so_far = a[0]
    max_ending_here = max(a[0], 0)

    for i in range(1, len(a)):
        max_ending_here += a[i]
        max_so_far = max(max_so_far, max_ending_here)
        max_ending_here = max(max_ending_here, 0)

    return max_so_far


def test():

    tests = [
        [-3, 2, -1, 4, -5],  # Expected output: 5
        [-1, -2, -3, -4, -5],  # Expected output: -1
    ]

    for arr in tests:
        print("Maximum contiguous sum of", arr, "is", maxSubArraySum(arr))


test()
