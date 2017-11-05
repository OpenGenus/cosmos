# Part of Cosmos by OpenGenus Foundation 

# Counts the number of values between 0 and a given number that satisfy the condition x+n = x^n (0<=x<=n)

# Works for both python 2 and python 3

n=int(input())
print (int(pow(2,(bin(n)[2:]).count('0'))))
