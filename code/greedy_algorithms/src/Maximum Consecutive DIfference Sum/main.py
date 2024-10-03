n= int(input())
A= list(map(int,input().strip().split()))
A.sort()
B, front, end = [], 0, n-1
while front<end:
	B.append(A[front])
	B.append(A[end])
	front+=1
	end-=1
if front==end:
	B.append(A[front])
total=0
for i in range(n):	
	total = total + abs(B[i]-B[(i+1)%n])
print(*B)
print(total)
