# Part of Cosmos by OpenGenus Foundation
import array

class Queue:
    def __init__(self, size_max):
        self.max = size_max
        self.head = 0
        self.tail = 0
        self.size = 0
        self.data = array.array('i', range(size_max))

    def empty(self):
        return self.size == 0

    def full(self):
        return self.size == self.max

    def enqueue(self, x):
        if self.size == self.max:
            print ("Queue full")
            return False
        self.data[self.tail] = x
        self.size += 1
        self.tail += 1
        if self.tail == self.max:
            self.tail = 0
        return True

    def dequeue(self):
        if self.size == 0:
            return None
        x = self.data[self.head]
        self.size -= 1
        self.head += 1
        if self.head == self.max:
            self.head = 0
        return x

print ("Enter the size of Queue")
n = int(input())
q = Queue(n)
while True:
    print
    print ("Press E to enqueue an element")
    print ("Press D to dequeue an element")
    print ("Press X to exit")
    opt = input().strip()
    if opt == "E":
        if q.size == q.max:
            print ("Queue is full")
            continue
        print ("Enter the element")
        ele = int(input())
        q.enqueue(ele)
        continue
    if opt == "D":
        ele = q.dequeue()
        if ele == None:
            print ("Queue is empty")
        else:
            print ("Element is", ele)
    if opt == "X":
        break
