import bisect
import random
import linear_search
import binary_search
import fibonacci_search

search_func = linear_search.linear_search
search_func = binary_search.binary_search
search_func = fibonacci_search.fibonacci_search


COMPARE_MODE = "ANY_SAME_NODE"
'COMPARE_MODE = "LOWER_BOUND"'


ELEM_MODE = "ALLOW_DUPLICATE"
'ELEM_MODE = "UNIQUE"'


def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    return -1


def fill(arr, size):
	i = 0
	if ELEM_MODE == "ALLOW_DUPLICATE":
		while len(arr) < size:
			arr.extend([i])
			if random.randint(0, 2) % 2:
				arr.extend([i])
			i += 1

	elif ELEM_MODE == "UNIQUE":
		while len(arr) < size:
			arr.extend([i])
			i += 1


def testSizeByTimes(size, times):
	for t in range(times):
		arr = []
		fill(arr, size)
		for i in range(-30, len(arr) * 2):
			expect = index(arr, i)
			actual = search_func(arr, i);
			if COMPARE_MODE == "ANY_SAME_NODE":
				assert expect == actual or (expect != -1 and arr[expect] == arr[actual])
			elif COMPARE_MODE == "LOWER_BOUND":
				assert expect == actual


testSizeByTimes(0, 1)
testSizeByTimes(1, 1)
testSizeByTimes(2, 1000)
testSizeByTimes(3, 1000)
testSizeByTimes(random.randint(1e5, 1e6), 1)

print("passed")

