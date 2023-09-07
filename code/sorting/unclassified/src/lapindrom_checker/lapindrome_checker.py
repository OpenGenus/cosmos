# part of cosmos by opengenus foundation


def isLapindrome(string):
    mid = len(string) // 2
    delim = mid
    if len(string) % 2 == 1:
        delim += 1  # if string has odd number of characters

    first_half = string[:mid]
    second_half = string[delim:]

    first_half = "".join(sorted(first_half))
    second_half = "".join(sorted(second_half))

    return first_half == second_half


testCase1 = "xyzyx"
testCase2 = "abcdbba"

if isLapindrome(testCase1):
    print("Lapindrome")
else:
    print("Not a Lapindrome")

if isLapindrome(testCase2):
    print("Lapindrome")
else:
    print("Not a Lapindrome")
