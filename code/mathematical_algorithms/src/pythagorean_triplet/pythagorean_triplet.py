"""
A Pythagorean triplet is a set of three natural numbers, a<b<c, for which a^2 + b^2 = c^2
Given N, Check if there exists any Pythagorean triplet for which a+b+c=N
Find maximum possible value of abc among all such Pythagorean triplets, If there is no such Pythagorean triplet print -1.
"""

N = int(input())
arr = [1,1,1]
for i in range(1,N):
    for j in range(i+1, N):
        if i + j > N:
            break
        for k in range(j+1, N):
            if i + j + k > N:
                break
            if i*i + j*j == k*k and i + j + k == N:
                if i*j*k > arr[0]*arr[1]*arr[2]:
                    arr = [i,j,k]

prod = arr[0]*arr[1]*arr[2]
if prod > 1:
    print(f"{arr[0]}^2 + {arr[1]}^2 = {arr[2]}^2, Product = {prod}")
else:
    print(-1)