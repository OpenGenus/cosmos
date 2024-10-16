def maximum_sum_subarray(arr, n):
    min_sum = 0
    res = 0
    prefixSum = []
    prefixSum.append(arr[0])
    for i in range(1, n):
        prefixSum.append(prefixSum[i-1] + arr[i])
    for i in range(n):
        res = max(res, prefixSum[i] - min_sum)
        min_sum = min(min_sum, prefixSum[i])
    return res

n = int(input("Enter the size of the array: "))
a = []
for i in range(n):
    a.append(int(input("Enter element no. "+ str(i+1)+": ")))

print("Result: ", maximum_sum_subarray(a, n))
