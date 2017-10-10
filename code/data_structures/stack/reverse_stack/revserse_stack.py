# reverse stack program


class Stack():
    def __init__(self):
        self.elements = []
        pass

    def push(self, element):
        self.elements.append(element)
        pass

    def show(self):
        print(" ".join(self.elements))
        pass

    def reverse(self):
        self.elements = reversed(self.elements)
        pass
    pass


stk = Stack()
# adding 5 elements
x = input()
stk.push(x)
x = input()
stk.push(x)
x = input()
stk.push(x)
x = input()
stk.push(x)
x = input()
stk.push(x)

# printing original value
print("ORIGINAL STACK")
stk.show()

# revering stack
stk.reverse()

# printing new stack
print("NEW STACK")
stk.show()
