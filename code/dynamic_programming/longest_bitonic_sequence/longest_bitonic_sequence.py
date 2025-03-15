# Part of Cosmos by Open Genus Foundation

def lbs(arr):
    n = len(arr)
    lis = [1 for i in range(n+1)]
 
    # Compute LIS values from left to right
    for i in range(1 , n):
        for j in range(0 , i):
            if ((arr[i] > arr[j]) and (lis[i] < lis[j] +1)):
                lis[i] = lis[j] + 1

    lds = [1 for i in range(n+1)]

    for i in reversed(range(n-1)): #loop from n-2 downto 0
        for j in reversed(range(i-1 ,n)): #loop from n-1 downto i-1
            if(arr[i] > arr[j] and lds[i] < lds[j] + 1):
                lds[i] = lds[j] + 1
 
 
    # Return the maximum value of (lis[i] + lds[i] - 1)
    maximum = lis[0] + lds[0] - 1
    for i in range(1 , n):
        maximum = max((lis[i] + lds[i]-1), maximum)
     
    return maximum
 
# Driver program to test the above function
arr =  [0 , 8 , 4, 12, 2, 10 , 6 , 14 , 1 , 9 , 5 , 13,
        3, 11 , 7 , 15]
print "Length of Longest Bitonic Sequence : ",lbs(arr)
 