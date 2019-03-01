# Part of Cosmos by OpenGenus Foundation


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


user_input = input("Enter the number: ")


print("\n----- Iterative Approach -----")
new_str = replace_0_5_iterative(user_input)
print("Modified number: " + new_str)

print("\n----- Python Replace Approach -----")
new_str = replace_0_5_pythonic(user_input)
print("Modified number: " + new_str)
