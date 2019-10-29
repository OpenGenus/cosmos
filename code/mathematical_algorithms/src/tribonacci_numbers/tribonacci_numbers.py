n = int(input())
a = []
a.append(0)
a.append(0)
a.append(1) # initializing first three of numbers of tibonacci series
for i in range(3, n):
    a.append(a[i - 1] + a[i - 2] + a[i - 3]) # adding the sum of previous three to the series

for i in a:
    print(i, end=" ") #final series print
