def setithBit(n,i):
 
    # ith bit of n is being
    # set by this operation
    return ((1 << i) | n)
     
# Driver code
 
n = 10
i = 2
 
print("Kth bit set number = ", setithBit(n, i))
 
