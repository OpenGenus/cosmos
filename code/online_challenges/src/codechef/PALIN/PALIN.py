t = int(input())

while t > 0:
    t -= 1

    st = input()

    a = list(map(int, st))
    n = len(a)

    temp = [9] * n

    if a == temp:
        ans = [0] * (n + 1)
        ans[0] = ans[n] = 1

        for i in range(n + 1):
            print(ans[i], end="")
        print()
    else:

        if n % 2 == 0:
            ini = n // 2 - 1
            inj = n // 2
        else:
            ini = inj = n // 2
			
        i = ini
        j = inj

        flag = 0
        while (i >= 0) and (j < n) and (a[i] == a[j]):
            i -= 1
            j += 1
			
        if (i < 0) and (j >= n):
            flag = 1
        else:

            if a[j] > a[i]:
                flag = 1
				
        if flag == 1:
            i = ini
            j = inj

            c = 1
            while (i >= 0) and (c != 0):
                a[i] += c

                if a[i] == 10:
                    a[i] = 0
                else:
                    c = 0
                i -= 1
        i = ini
        j = inj

        while (i >= 0) and (j < n):
            a[j] = a[i]
            i -= 1
            j += 1
        for i in range(n):
            print(a[i], end="")
        print()
