t = int(input())

while t > 0:
    t -= 1

    n = int(input())

    a = list(map(int, input().split()))

    if sum(a) < 100:
        print("NO")
    else:
        if sum(a) == 100:
            print("YES")
        else:
            count = sum(i == 0 for i in a)

            n = n - count
            s = sum(a) - n
            if s >= 100:
                print("NO")
            else:
                e = 1 - 0.000001
                if (100 - s) <= n * e:
                    print("YES")
                else:
                    print("NO")
