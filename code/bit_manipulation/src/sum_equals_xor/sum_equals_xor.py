# Counts the number of values between 0 and a given number that satisfy the condition x+n = x^n (0<=x<=n)

# Works for both python 2 and python 3

n = int(input("Enter number n"))
# x^n = x+n means that x can contain one's only in its binary representation where it is 0 in n and vice versa.
# To Implement it we calculate number of 0's in the binary representation of n and return the answer as pow(2,n) as there will be two possibilities for each of the 0's in n i.e. 1 and 0.
print(int(pow(2, (bin(n)[2:]).count("0"))))
