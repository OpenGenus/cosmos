import math

t = int(input())

while t > 0:
    t -= 1
    n = int(input())

    arr = list(map(int, input().split()))
    count = {}
    ans = 1

    for i in range(n):
        for j in range(2, int(math.sqrt(arr[i])) + 1, 1):
            while arr[i] % j == 0:
                if j in count:
                    count[j] += 1
                else:
                    count[j] = 1
                arr[i] = arr[i] // j
        if arr[i] > 1:
            if arr[i] in count:
                count[arr[i]] += 1
            else:
                count[arr[i]] = 1
    for i in count:
        ans = ans * (count[i] + 1)
    print(ans)
