import math

def jumpSearch(arr, x):
	n  = len(arr)
	jump = int(math.sqrt(n ))
	left, right = 0, 0
	while left < n  and arr[left] <= x:
		right = min(n  - 1, left + jump)
		if arr[left] <= x and arr[right] >= x:
			break
		left += jump;

	if left >= n  or arr[left] > x:
		return -1

	right = min(n-1, right)

	temp = left
	while temp <= right and arr[temp] <= x:
		if arr[temp] == x:
			return temp
		temp += 1

	return -1

def test(x):
	arr = [7, 18, 24, 12, 47, 84, 14]
	index = jumpSearch(arr, x)

	if index != -1:
		print "The element",x,"is at the index",index
	else:
		print "Element",x,"not found!"


test(18)
