class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


def reverse(stack):
    items = []
    while not stack.isEmpty():
        items.append(stack.pop())
    for item in items:
        stack.push(item)
    return stack


if __name__ == '__main__':

    inputStack = Stack()

    print("Enter the item to push into the stack and press Enter (type 'rev' to reverse the stack)")
    while True:
        inputItem = input('input item: ')

        if inputItem == 'rev' and inputStack.isEmpty():
            print('The stack is empty')
            print('========== +++++ ===========')
        elif inputItem == 'rev':
            reverseStack = reverse(inputStack)
            print('reversed stack: ', reverseStack.items)
            break
        else:
            inputStack.push(inputItem)
            print('current stack:', inputStack.items)
