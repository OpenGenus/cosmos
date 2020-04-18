# Brick sort is a similar to bubble sort in terms of sorting array
# It sorts the array in terms of odd and even index places elements
def BrickSort(l):
    # l is the arguement used that contains the unsorted element
    # n is the variable that contains the no. of elements in the array
    n = len(l)
    # k variable is used to denote if array is sorted after the sorting process.
    # it is initialised 0 to check if array is sorted after every iteration
    k = 0
    while k == 0:
        # k is set to 1  when loop conditions is true
        k = 1
        # this for loop sorts the even indexed element in an array
        for i in range(0, n - 1, 2):
            if l[i] > l[i + 1]:
                l[i], l[i + 1] = l[i + 1], l[i]
                k = 0
        # k is set to 0 whenever loop is executed
        # the next loop sorts the odd indexed element in the array
        for i in range(1, n - 1, 2):
            if l[i] > l[i + 1]:
                l[i], l[i + 1] = l[i + 1], l[i]
                k = 0
    # array is returned once it is sorted
    return l


# sample array with unsorted elements
l = [4, 2, 1, 6, 4, 67, 23, 11, 9]
m = BrickSort(l)
for i in m:
    print(i, end=" ")
# output-> 1 2 4 4 6 9 11 23 67
