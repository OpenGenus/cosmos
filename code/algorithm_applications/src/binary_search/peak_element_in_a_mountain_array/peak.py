


# the peak element in the array
def findPeak(arr):
	

	left = 0


	right = len(arr) - 1

	while (left < right):

	
		mid = left + (right - left) // 2

	
		if (arr[mid] < arr[(mid + 1)]):

			left = mid + 1

		else:

		
			right = mid

	return left


def BS(X, left, right, arr):
	
	while (left <= right):

		mid = left + (right - left) // 2

		if (arr[mid] == X):
			return mid

		elif (X > arr[mid]):

			left = mid + 1

		else:

			right = mid - 1

	return -1

def reverseBS(X, left, right, arr):
	
	while (left <= right):

		mid = left + (right - left) 

		if (arr[mid] == X):
			return mid

		elif (X > arr[mid]):

			right = mid - 1

		else:
			
			left = mid + 1
			
	return -1

def findInMA(X, mountainArr):
	
	peakIndex = findPeak(mountainArr)

	res = -1


	if (X >= mountainArr[0] and
		X <= mountainArr[peakIndex]):

		res = BS(X, 0, peakIndex, mountainArr)

	
	if (res == -1):

		res = reverseBS(X, peakIndex + 1,
						mountainArr.size() - 1,
						mountainArr)

	print(res)

if __name__ == "__main__":

	
	X = 3

	arr = [ 1, 2, 3, 4, 5, 3, 1 ]

	findInMA(X, arr)


