def gcd(a, b):
    if (a == b):
        return a
 
    if (a == 0):
        return b
 
    if (b == 0):
        return a
 
    if ((~a & 1) == 1):
        if ((b & 1) == 1):
            return gcd(a >> 1, b)
        else:
            return (gcd(a >> 1, b >> 1) << 1)
 
    if ((~b & 1) == 1):
        return gcd(a, b >> 1)
 
    if (a > b):
        return gcd((a - b) >> 1, b)
 
    return gcd((b - a) >> 1, a)
 
 
a, b = 34, 17
print("Gcd of given numbers is ",
      gcd(a, b))
