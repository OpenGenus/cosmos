"""
    Program to implement Miller-rabin Primality Test
    Part of cosmos by OpenGenus Foundation 
"""
import random

#Main method(function) to check primality of a number
def isprime(number):
    iterations = 4 #no. of iterations to run test
    
    #corner cases
    if number <= 1 or number == 4:
        return False
    elif number == 2 or number == 3 or number == 5:
        return True
    else:
        d = number - 1
        #Dividing 'd' till it become a odd number
        while(d % 2==0):
            d /= 2
        #checking primality using utility function "miller_rabin_primality" 
        #for no.of iteration times 
        for i in range(iterations):
            if miller_rabin_primality(d,number)==False:
                return False #if number is surely composite
                
        #if the number may probably a prime number return True
        return True
        
#Utility function to calculate (x^exp)%mod
def power(x, exp, mod):
    
    result = 1
    x = x % mod
    
    while exp > 0:
        #if power is odd
        if exp % 2 == 1:
            result = (result*x) % mod
            
        exp = exp//2
        x = (x*x) % mod
        
    return result
    
    
    
#Utility function checking for miller_rabin primality test 
def miller_rabin_primality(d,n):
    
    #choose a random number "a"
    a=random.randint(2, n-2) % (n-4)
    
    #compute (a^d)%n
    x=power(a,d,n)
    
    if x == 1 or x == n-1:
        return True
        
    while(d != n-1):
        #Square x till one of the folling condition satisfy:
            #1. (x^2)%n!=1, if (x^2)%n==1 , this implies 'n' fails the primality test
            #2. (x^2)%n!=(n-1)  if (x^2)%n==(n-1), this implies 'n' still may be a prime number
        x = (x*x) % n
        d *= 2
        if x == 1:
            return False
        elif x == n-1:
            return True
            
    return False

        
if __name__ == '__main__':
    #illustration by provinding example for a prime number and a composite number
    print(isprime(13))  #prime number returns true
    print(isprime(16))  # composite number returns False
