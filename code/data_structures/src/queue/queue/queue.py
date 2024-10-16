# Part of Cosmos by OpenGenus Foundation
class Queue:
    def __init__(self, size_max):
        self.data = [None] * (size_max + 1)
        self.max = (size_max + 1)
        self.head = 0
        self.tail = 0

    def empty(self):
        return self.head == self.tail

    def full(self):
        return self.head == (self.tail + 1) % self.max

    def enqueue(self, x):
        if self.full():
            print("Queue full")
            return False
        self.data[self.tail] = x
        self.tail = (self.tail + 1) % self.max
        return True

    def dequeue(self):
        if self.empty():
            print("Queue empty")
            return None
        x = self.data[self.head]
        self.head = (self.head + 1) % self.max
        return x

    def top(self):
        if self.empty():
            print("Queue empty")
            return None
        return self.data[self.head]

    def display(self):
        cur = self.head
        while cur != self.tail:
            print(self.data[cur])
            cur = (cur + 1) % self.max

print("Enter the size of Queue")
n = int(input())
q = Queue(n)
while True:
    print("Press E to enqueue an element")
    print("Press D to dequeue an element")
    print("Press P to display all elements of the queue")
    print("Press T to show top element of the queue")
    print("Press X to exit")
    opt = input().strip()
    if opt == "E":
        if q.full():
            print("Queue is full")
            continue
        print("Enter the element")
        ele = int(input())
        q.enqueue(ele)
        continue
    if opt == "D":
        ele = q.dequeue()
        if ele == None:
            print("Queue is empty")
        else:
            print("Element is", ele)
    if opt == "P":
        q.display()
    if opt == "T":
        print(q.top())
    if opt == "X":
        break
