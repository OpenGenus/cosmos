n = int(input())

a = list(map(int, input().split()))
ans = 0
for i in range(32):
    t = 1 << i
    count = 0
    for j in range(n):
        if a[j] & t:
            count += 1
    ans += ((count * (count - 1)) >> 1) * (1 << i)

print(ans)
