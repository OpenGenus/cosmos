def interpolationSearch(arr, n, x):
    low = 0
    high = (n - 1)

    while low <= high and x >= arr[low] and x <= arr[high]:
        mid  = low + int(((float(high - low) / ( arr[high] - arr[low])) * ( x - arr[low])))

        if arr[mid] == x:
            return mid

        if arr[mid] < x:
            low = mid + 1;

        else:
            high = mid - 1;

    return -1

def test(x):
    arr = [10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47]
    n = len(arr)

    index = interpolationSearch(arr, n, x)

    if index != -1:
        print "The element",x,"is at the index",index
    else:
        print "Element",x,"not found!"


test(123)
