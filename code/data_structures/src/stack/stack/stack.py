# Author: Alex Day
# Purpose: Stack implementation with array in python
# Date: October 2 2017


# Part of Cosmos by OpenGenus Foundation
class Stack(object):
    # Quasi-Constructor
    def __init__(self):
        # Object data members
        self.stack_arr = []  # Just an array

    # When the client requests a push simply add the data to the list
    def push(self, data):
        self.stack_arr.append(data)

    # When the client requests a pop just run the pop function on the array
    def pop(self):
        assert len(self.stack_arr) > 0, "The stack is empty!"
        return self.stack_arr.pop()

    # When the client requests a peek just return the top value
    def peek(self):
        assert len(self.stack_arr) > 0, "The stack is empty!"
        return self.stack_arr[-1]

    # When the client requests is_empty returns if the stack is empty
    def is_empty(self):
        return ("The stack is empty!", "The stack is not empty!")[
            len(self.stack_arr) > 0
        ]


def main():
    stk = Stack()
    stk.push(1)
    stk.push(2)

    print(stk.is_empty())
    print(stk.peek())

    print(stk.pop())
    print(stk.pop())
    print(stk.is_empty())


if __name__ == "__main__":
    main()
