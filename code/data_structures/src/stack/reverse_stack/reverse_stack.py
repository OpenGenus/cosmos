"""
Part of Cosmos by OpenGenus Foundation
"""

# stack class
class Stack:
    def __init__(self):
        self.items = []

    # check if the stack is empty
    def isEmpty(self):
        return self.items == []

    # push item into the stack
    def push(self, item):
        self.items.append(item)

    # pop item from the stack
    def pop(self):
        return self.items.pop()

    # get latest item in the stack
    def peek(self):
        return self.items[len(self.items) - 1]

    # get stack size
    def size(self):
        return len(self.items)


# reverse stack function
def reverse(stack):
    # temp list
    items = []

    # pop items in the stack and append to the list
    # this will reverse items in the stack
    while not stack.isEmpty():
        items.append(stack.pop())

    # push reversed item back to the stack
    for item in items:
        stack.push(item)

    # return
    return stack


if __name__ == "__main__":
    # init the stack
    inputStack = Stack()

    print(
        "Enter the item to push into the stack and press Enter (type 'rev' to reverse the stack)"
    )
    while True:
        # get input item
        inputItem = input("input item: ")

        if inputItem == "rev" and inputStack.isEmpty():
            # if stack is empty, return message
            print("The stack is empty")
            print("========== +++++ ===========")
        elif inputItem == "rev":
            # reverse the stack
            reverseStack = reverse(inputStack)
            print("reversed stack: ", reverseStack.items)
            break
        else:
            # push item into the stack
            inputStack.push(inputItem)
            print("current stack:", inputStack.items)
