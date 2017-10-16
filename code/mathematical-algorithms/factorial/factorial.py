 /* Part of Cosmos by OpenGenus Foundation 
  * Factorial without using recursion
  */ 
def factorial(n):
  f = 1
  for i in range(1, n +1):
     f *= i
  return f

n = int(input())

print(factorial(n))
