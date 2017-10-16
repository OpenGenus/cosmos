# -----------------------------
#  Part of cosmos from OpenGenus Foundation
# -----------------------------

# function to perform algo and check if string is lapindrome or not
def is_lapindrome(string):
    # getting string length
    length = len(string)

    # getting mid
    mid = length // 2   # integer division done in order to prevent floating number

    # getting delimiter
    delim = mid # for even
    if length % 2 == 1:
        delim +=1 # for odd -> in odd length we have to ignore the middle most value

    # slicing string
    left = string[:mid]
    right = string[delim:]

    # sorting  string
    left_sorted = sorted(left) # this will return a list
    right_sorted = sorted(right) # this will return a list

    # converting list to string
    left = "".join(left_sorted)
    right = "".join(right_sorted)

    # equating
    if left == right:
        return True
    else:
        return False



"""
DEMONSTRATING
"""
# CASE 1
if(is_lapindrome("abba")):
    print("lapindrome")
    pass
else:
    print("not lapindrome")
    pass

# CASE 2
if(is_lapindrome("aaabba")):
    print("lapindrome")
    pass
else:
    print("not lapindrome")
    pass
