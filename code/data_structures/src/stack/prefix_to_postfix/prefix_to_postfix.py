# Converting prefix to its equivalent postfix notation.
# Part of Cosmos by OpenGenus Foundation
postfix = []
operator = -10
operand = -20
empty = -50


def typeof(s):
    if s is "(" or s is ")":
        return operator
    elif s is "+" or s is "-" or s is "*" or s is "%" or s is "/":
        return operator
    elif s is " ":
        return empty
    else:
        return operand


prefix = input("Enter the prefix notation : ")
prefix = prefix[::-1]
print(prefix)
for i in prefix:
    type = typeof(i)
    if type is operand:
        postfix.append(i)
    elif type is operator:
        op_first = postfix.pop()
        op_second = postfix.pop()
        postfix.append(op_first + op_second + i)
    elif type is empty:
        continue

print("It's postfix notation is ", "".join(postfix))
