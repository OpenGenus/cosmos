t = int(input())

while t > 0:
    t -= 1
    ans = 1

    n, k = map(int, input().split())

    if n == k:
        print(ans)
    else:
        n -= 1
        k -= 1

        if k > n / 2:
            k = n - k
        ans = 1
        for i in range(k):
            ans *= n - i
            ans /= i + 1
        print(int(ans))
