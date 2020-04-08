import sys
import numpy as np

n, q = map(int, input().split())

a = np.zeros(n, dtype=bool)
ans = []

for i in range(q):
    flag, start, end = map(int, input().split())

    if flag == 0:
        a[start : end + 1] = ~a[start : end + 1]
    else:
        ans.append(a[start : end + 1].sum())
print("\n".join(map(str, ans)))
