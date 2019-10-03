# Part of Cosmos by OpenGenus Foundation
import array


class Queue:
    def __init__(self, size_max):
        self.max = size_max
        self.size = 0
        self.data = []

    def empty(self):
        return self.size == 0

    def full(self):
        return self.size == self.max

    def enqueue(self, x):
        if self.size == self.max:
            print("Queue full")
            return False
        self.data.insert(0, x)
        self.size += 1
        return True

    def dequeue(self):
        if self.size == 0:
            return None
        x = self.data.pop()
        self.size -= 1
        return x

    def display(self):
        if self.size == 0:
            print("Queue is empty")
        else:
            out = ""
            for ele in self.data:
                out = out + " " + str(ele)
            print(out[::-1])
        return


print("Enter the size of Queue")
n = int(input())
q = Queue(n)
while True:
    print("Press E to enqueue an element")
    print("Press D to dequeue an element")
    print("Press P to display all elements of the queue")
    print("Press X to exit")
    opt = input().strip()
    if opt == "E":
        if q.size == q.max:
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
    if opt == "X":
        break
