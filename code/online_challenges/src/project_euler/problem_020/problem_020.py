factorial = 1
for i in range(100):
	factorial *= (i + 1)
sum = 0
while factorial > 0:
	sum += factorial % 10
	factorial = factorial // 10
print(sum)