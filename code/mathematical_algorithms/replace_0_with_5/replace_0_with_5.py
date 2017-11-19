# Part of Cosmos by OpenGenus Foundation

from __future__ import print_function

def replace_0_5_iterative(user_input):
    modified = []
    for i in user_input:
        if i == "0":
            modified.append("5")
        else:
            modified.append(i)
    return "".join(modified)

def replace_0_5_pythonic(user_input):
    return user_input.replace("0", "5")

# ----------------------
#   Determining Python Versions
# ----------------------
try:  # for python 2.x
    user_input = raw_input("Enter the number: ")
    pass
except NameError:  # for python 3.x
    user_input = input('Enter the number: ')
    pass


print("\n----- Iterative Approach -----")
new_str = replace_0_5_iterative(user_input)
print("Modified number: " + new_str)

print("\n----- Python Replace Approach -----")
new_str = replace_0_5_pythonic(user_input)
print("Modified number: " + new_str)

