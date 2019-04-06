from sys import argv


# N'th fibonacci number using Dynamic Programming
def fibonacci(n):

    # Taking 1st two fibonacci nubers as 0 and 1
    arr = [0, 1]

    while len(arr) < n + 1:
        arr.append(0)

    if n <= 1:
        return n
    else:
        if arr[n - 1] == 0:
            arr[n - 1] = fibonacci(n - 1)

        if arr[n - 2] == 0:
            arr[n - 2] = fibonacci(n - 2)

    arr[n] = arr[n - 2] + arr[n - 1]
    return arr[n]


print(fibonacci(int(argv[1])))
