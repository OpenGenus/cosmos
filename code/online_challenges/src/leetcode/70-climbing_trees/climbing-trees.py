def climbStairs(n):
   store={}
   def helper(n):
       if n==1 or n==2:
          return n
       elif n in store:
          return store[n]
       else:
          store[n]= helper(n-1)+ helper(n-2)
          return store[n]
          
    return helper(n)
    
climbStairs(4)    
          
