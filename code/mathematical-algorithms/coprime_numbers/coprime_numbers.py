def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def coprime(a, b):
    return gcd(a, b) == 1

a,b = map(int,input().split())
print(coprime(a,b))
