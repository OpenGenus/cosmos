# Part of Cosmos by OpenGenus Foundation


class Stack:
    def __init__(self):
        self.items = []

    def push(self, x):
        self.items.append(x)

    def pop(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

    def is_empty(self):
        return self.size() == 0


class Queue:
    def __init__(self):
        self.s1 = Stack()
        self.s2 = Stack()

    def enqueue(self, p):
        self.s1.push(p)

    def dequeue(self):
        # pop all elements in s1 onto s2
        while not self.s1.is_empty():
            self.s2.push(self.s1.pop())

        # pop all elements of s1
        return_value = self.s2.pop()

        # re pop all elements of s2 onto s1
        while not self.s2.is_empty():
            self.s1.push(self.s2.pop())

        return return_value


if __name__ == "__main__":
    from random import choice

    a = Queue()

    l = [choice(range(1, 500)) for i in range(1, 10)]
    print(l)

    for i in l:
        a.enqueue(i)

    for i in range(len(l)):
        print("Dequeued:", a.dequeue())
