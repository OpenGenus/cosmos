def interpolation_search(arr, x):
    low = 0
    high = len(arr) - 1

    while low <= high and x >= arr[low] and x <= arr[high]:
        mid = low + int((float(high - low) / (arr[high] - arr[low] + 1)) * (x - arr[low]))

        if arr[mid] == x:
            return mid

        if arr[mid] < x:
            low = mid + 1

        else:
            high = mid - 1

    return -1
