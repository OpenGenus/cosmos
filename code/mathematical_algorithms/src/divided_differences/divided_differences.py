# Function for calculating divided difference table
def dividedDiffTable(x, y, n):

	for i in range(1, n):
		for j in range(n - i):
			y[j][i] = ((y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]))
	return y

# number of inputs given
n = 4
y = [[0 for i in range(10)]
		for j in range(10)]
x = [ 1.0, 2.0, 3.0, 4.0 ]

# y[][] is used for divided difference table where y[][0] is used for input
y[0][0] = 1.0
y[1][0] = 8.0
y[2][0] = 27.0
y[3][0] = 64.0

# calculating divided difference table
y=dividedDiffTable(x, y, n)

# displaying divided difference table
L = []
for i in range(2*n - 1):
	A = []
	for j in range(n):
		A.append("   ")
	L.append(A)

for i in range(n):
	j = i
	count = 0
	while j < 2*n-1:
		if count < n-i:
			L[j][i] = str(round(y[count][i],4))
		count = count + 1
		j = j + 2

for i in range(2*n-1):
	for j in range(n):
		print(L[i][j],end = " ")
	print("")