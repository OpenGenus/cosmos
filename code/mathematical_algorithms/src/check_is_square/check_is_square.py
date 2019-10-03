# Part of Cosmos by OpenGenus Foundation


def checkIfSquare(n):
    start = 0
    end = int(n)
    while start <= end:

        mid = (start + end) // 2
        val = mid * mid

        if val == int(n):
            return True
        elif val < int(n):
            start = mid + 1
        else:
            end = mid - 1

    return False


version = sys.version_info[0]
print("Enter a positive number :")
n = input()
if checkIfSquare(n):
    print("Yes")
else:
    print("No")
