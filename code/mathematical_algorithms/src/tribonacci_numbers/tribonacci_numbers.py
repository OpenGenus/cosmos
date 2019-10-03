n = int(input())
a = []
a.append(0)
a.append(0)
a.append(1)
for i in range(3, n):
    a.append(a[i - 1] + a[i - 2] + a[i - 3])

for i in a:
    print(i)
