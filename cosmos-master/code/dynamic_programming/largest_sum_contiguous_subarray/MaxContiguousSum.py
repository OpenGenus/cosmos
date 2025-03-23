#Python program to calculate Largest contiguous subarray Sum
#This program implements dynamic programming

def Max(b,size):
 
    answer=b[0]
    temp=b[0]
    for i in range(1,size):
        temp = max( b[i], temp+b[i] )
        answer = max(answer,temp)
 
    return answer
 
b = [-2, -3, 4, -1, -2, 1, 5, -3]
print ("Maximum Contiguous Sum is" , Max(b,len(b)))

#Output:
#Maximum Contiguous Sum is 7
