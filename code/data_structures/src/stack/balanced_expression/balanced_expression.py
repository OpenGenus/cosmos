# simple program to check if an expression is balanced using stack
stack = []
def checkBalanced(expr):
    for i in expr:
        if i == "{" or i == "[" or i == "(":
            stack.append(i)
        elif i == "}" or i == "]" or i == ")":
            temp = stack.pop()
            if i == "}" and temp != "{":
                return False
            elif i == "]" and temp != "[":
                return False
            elif i == ")" and temp != "(":
                return False

    return True

# main function
expr = input()
result = checkBalanced(expr)
if result:
    print("Expression is balanced")
else:
    print("Expression is not balanced")
