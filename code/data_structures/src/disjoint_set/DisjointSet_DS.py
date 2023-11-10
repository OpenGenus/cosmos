f = []
f = [0 for x in range(100)]

def find(f, node):
	if(f[node] == node):
		return node
	else:
		f[node] = find(f, f[node])
		return f[node]

def union_set(f, x, y):
	f[find(f, x)] = find(f, y)
	return f

arr = []
arr = [0 for x in range(10)]
for i in range(1,11):
	arr[i-1] = i
	f[i] = i
union_set(f,1,3)
union_set(f,4,5)
union_set(f,1,2)
union_set(f,1,5)
union_set(f,2,8)
union_set(f,9,10)
union_set(f,1,9)
union_set(f,2,7)
union_set(f,3,6)

for i in arr:
	print(f"{i}->{f[i]}\n")