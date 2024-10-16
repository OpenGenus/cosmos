# Given keys and frequency, calculate the most optimal binary search tree that can be created making use of minimum cost

keys = list(map(int, input("Enter the list of keys").split()))
freq = list(map(int, input("Enter the list of frequencies").split()))
z = []
n = len(keys)
for i in range(n):
    z += [[keys[i], freq[i]]]
z.sort()
cost = [[10 ** 18 for i in range(n)] for j in range(n)]  # initialising with infinity
for i in range(n):
    keys[i] = z[i][0]
    freq[i] = z[i][1]
s = [freq[0]]
for i in range(n - 1):
    s += [s[i] + freq[i + 1]]
for i in range(n):
    cost[i][i] = freq[i]
for i in range(2, n + 1):
    for j in range(n - i + 1):
        l = j
        r = l + i - 1
        for k in range(l, r + 1):
            if k == l:
                cost[l][r] = min(cost[l][r], cost[l + 1][r])
            elif k == r:
                cost[l][r] = min(cost[l][r], cost[l][r - 1])
            else:
                cost[l][r] = min(cost[l][r], cost[l][k] + cost[k + 1][r])

        cost[l][r] += s[r] - s[l] + freq[l]

print("Cost of Optimal BST is : ", cost[0][n - 1])
