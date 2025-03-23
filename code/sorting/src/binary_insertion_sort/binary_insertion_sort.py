# Binary insertion sort finds the appropriate index to place element using binary search
# it has less complexity as compared to insertion sort
def BinarySearch(l, k, p, q):
    # l is the arguement used that contains the unsorted element
    # k variable contains the elements which is to be inserted
    # p variable contains the index of first element from unsorted array
    # q contains the index of the last element from unsorted array
    if p == q:
        if l[p] > k:
            return p
        else:
            return p + 1
    if p > q:
        return p
    # m contains the index of middle element from array
    m = int((p + q) / 2)
    # To check if middle element is smaller than selected element
    if l[m] < k:
        return BinarySearch(l, k, m + 1, q)
    # To check if middle element is greater than selected element
    elif l[m] > k:
        return BinarySearch(l, k, p, m - 1)
    # if middle element is equal to selected element
    else:
        return m


# InsertionSort function traverses via the unsorted array
def InsertionSort(l):
    # for loop contains the array starting from index 1
    for i in range(1, len(l)):
        k = l[i]
        # BinarySearch function finds the appropriate index for the element
        j = BinarySearch(l, k, 0, i - 1)
        # once the index is found, Element is placed at the index in an array
        l = l[:j] + [k] + l[j:i] + l[i + 1 :]
    return l


# To display the sorted array
print("New Array:")
l = [37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54]
print(InsertionSort(l))

# output->0 12 17 23 31 37 46 54 72 88 100
