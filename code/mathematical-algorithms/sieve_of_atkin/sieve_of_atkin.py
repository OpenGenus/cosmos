import math

def sieveOfAtkin(num):
    P = [2,3]
    sieve=[False]*(num+1)
    for x in range(1,int(math.sqrt(num))+1):
        for y in range(1,int(math.sqrt(num))+1):
            n = 4*x**2 + y**2
            if n<=num and (n%12==1 or n%12==5) : sieve[n] = not sieve[n]
            n = 3*x**2+y**2
            if n<= num and n%12==7 : sieve[n] = not sieve[n]
            n = 3*x**2 - y**2
            if x>y and n<=num and n%12==11 : sieve[n] = not sieve[n]
    for x in range(5,int(math.sqrt(num))):
        if sieve[x]:
            for y in range(x**2,num+1,x**2):
                sieve[y] = False
    for p in range(5,num):
        if sieve[p] : P.append(p)
    return P

print sieveOfAtkin(1000)

