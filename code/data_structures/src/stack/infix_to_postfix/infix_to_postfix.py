# Part of Cosmos by OpenGenus Foundation
class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


def infix_to_postfix(exp):
    prec = {}
    prec["*"] = 3
    prec["/"] = 3
    prec["+"] = 2
    prec["-"] = 2
    prec["("] = 1

    s = Stack()
    postfix_list = []
    token_list = exp.split()

    for i in token_list:
        if i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or i in "1234567890":
            postfix_list.append(i)
        elif i == "(":
            s.push(i)
        elif i == ")":
            top_token = s.pop()
            while top_token != "(":
                postfix_list.append(top_token)
                top_token = s.pop()
        else:
            while (not s.is_empty()) and (prec[s.peek()] >= prec[i]):
                postfix_list.append(s.pop())
            s.push(i)

    while not s.is_empty():
        postfix_list.append(s.pop())
    return " ".join(postfix_list)


print(infix_to_postfix("A * B + C * D"))
print(infix_to_postfix("( A + B ) * C - ( D - E ) * ( F + G )"))
