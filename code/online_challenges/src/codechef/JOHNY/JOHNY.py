t = int(input())
for x in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    k = int(input())
    a = p[k - 1]
    p.sort()
    print(p.index(a) + 1)
