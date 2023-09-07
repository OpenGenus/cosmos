def wireLength(n, st):

    if n == 0:
        return 0
    if n == 1:
        return n + 1
    if st == "min":
        return n + 1 + wireLength(int(n / 2), st) + wireLength(n - int(n / 2) - 1, st)
    else:
        return n + 1 + wireLength(n - 1, st)


t = int(input())
while t > 0:
    t -= 1
    n, m = map(int, input().split())

    min_length = wireLength(n, "min")
    max_length = wireLength(n, "max")

    ans = 0
    if m < min_length:
        ans = -1
    elif m > max_length:
        ans = m - max_length
    else:
        ans = 0
    print(ans)
