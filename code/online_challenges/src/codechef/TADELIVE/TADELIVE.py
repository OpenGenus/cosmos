n, x, y = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

d = [abs(x - y) for x, y in zip(a, b)]

ind = [i[0] for i in sorted(enumerate(d), key=lambda x: x[1])]

tip = 0
for k in range(len(ind) - 1, -1, -1):
    i = ind[k]
    if a[i] > b[i]:
        if x > 0:
            tip += a[i]
            x = x - 1
        else:
            tip += b[i]
            y = y - 1
    else:
        if y > 0:
            tip += b[i]
            y = y - 1
        else:
            tip += a[i]
            x = x - 1
print(tip)
