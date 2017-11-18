i = 3
n = s = 1
while (i <= 10001):
    if (s == 1):
        x = 6*n -1
        s = 0
    else:
        x = 6*n +1
        s = 1
        n = n + 1
    r = x**.5
    p = 1
    t = 3
    while (t <= r):
        if (x%t == 0):
            p = 0
        t = t + 2
    if (p == 1):
        i = i + 1
print x