# Note: this implementation is the Dynamic Programming solution to the binomial coefficient
# from geeksforgeeks.com. The link is:
# https://www.geeksforgeeks.org/binomial-coefficient-dp-9/

 def binomialCoeff(n , k):

     # Declaring an empty array
     C = [0 for i in xrange(k+1)]
     C[0] = 1

     for i in range(1,n+1):

         # Compute next row of pascal triangle using
         # the previous row
         j = min(i ,k) 
         while (j>0):
             C[j] = C[j] + C[j-1]
             j -= 1

     return C[k]
