def gcd(n1, n2):
    remainder = 1
    while remainder != 0:
        remainder = n1 % n2
        n1 = n2
        n2 = remainder
    return n1

def lcm(n1, n2):
    return (n1 * n2) / gcd(n1, n2)

l = lcm(2, 3)

for i in range(1, 21):
    l = lcm(l, i)

print l