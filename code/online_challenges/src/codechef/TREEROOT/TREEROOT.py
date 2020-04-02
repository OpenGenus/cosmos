t = int(input())

while t > 0:
    t -= 1
    ans = 0

    n = int(input())

    for i in range(n):
        id, cid = map(int, input().split())

        ans += id - cid
    print(ans)
