def interpolation_search(arr, n, x):
    low = 0
    high = (n - 1)

    while low <= high and x >= arr[low] and x <= arr[high]:
        mid = low + int(
            ((float(high - low) / (arr[high] - arr[low])) * (x - arr[low])))

        if arr[mid] == x:
            return mid

        if arr[mid] < x:
            low = mid + 1

        else:
            high = mid - 1

    return -1
