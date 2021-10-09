count = 0
test_cases = int(input())
def cal(test_cases):
    arr = input()
    count = 0
    for i in range(len(arr)-1):
        if arr[i] == arr[i+1]:
            count += 1
    return count
for i in range(test_cases):
    print(cal(test_cases))
