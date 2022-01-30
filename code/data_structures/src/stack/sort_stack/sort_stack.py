class stack:
    def __init__(self):
        self.__stack = []
        pass

    # method to parse_stack if have already
    def parse_stack(self, stack):
        self.__stack = stack
        pass

    def push(self, value):
        self.__stack.append(value)
        pass

    def pop(self):
        self.__stack.pop()
        pass

    def get_elements(self):
        return self.__stack

    def sort(self):
        self.__stack = sorted(self.__stack)

    pass


# defining stack class instance
stk = stack()

# pushing elements in stack
stk.push(10)
stk.push(2)
stk.push(-1)

# viewing
print("Original Stack : ", stk.get_elements())

# sorting stack
stk.sort()

# viewing again
print("Sorted Stack : ", stk.get_elements())
