# This function returns new size of modified array.
def removeDuplicates(arr, n):
	if n == 0 or n == 1:
		return n

	temp = list(range(n))

	# Start traversing elements
	j = 0
	for i in range(0, n-1):
		if arr[i] != arr[i+1]:
			temp[j] = arr[i]
			j += 1
	temp[j] = arr[n-1]
	j += 1
	
	# Modify original array
	for i in range(0, j):
		arr[i] = temp[i]

	return j

# Driver code
arr = [1, 2, 2, 3, 4, 4, 4, 5, 5]
n = len(arr)

n = removeDuplicates(arr, n)

# Print updated array
for i in range(n):
	print ("%d"%(arr[i]), end = " ")
