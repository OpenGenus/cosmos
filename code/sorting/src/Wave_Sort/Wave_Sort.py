def sortWave(arr, n):
    arr.sort()
    # for i in range(0, n, 2):
    #     if i > 0 and arr[i-1] > arr[i]:
    #         arr[i], arr[i-1] = arr[i-1], arr[i]

    #     if i < n-1 and arr[i+1] > arr[i]:
    #         arr[i], arr[i+1] = arr[i+1], arr[i]

    for i in range(0,n-1,2):
        arr[i], arr[i+1] = arr[i+1], arr[i]

if __name__ == "__main__":
    arr = [10, 90, 49, 2, 1, 5, 23]
    sortWave(arr, len(arr))
    print(arr)