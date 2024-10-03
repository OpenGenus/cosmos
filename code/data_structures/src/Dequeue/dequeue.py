#create a node class
class Node:
    def __init__(self,data):
        self.data = data
        self.prev = None
        self.next = None

#create a deque class
class Dequeue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def insertFront(self,data):
        newNode = Node(data)
        if (self.head == None):
            self.head = newNode
            self.tail = newNode
            self.length = 1
        else:
            self.head.prev = newNode
            newNode.next = self.head
            self.head = newNode
            self.length += 1

    def insertRear(self,data):
        newNode = Node(data)
        if (self.tail == None):
            self.head = newNode
            self.tail = newNode
            self.length = 1
        else:
            self.tail.next = newNode
            newNode.prev = self.tail
            self.tail = newNode
            self.length += 1

    def deleteFront(self):
        if (self.head == None):
            return "Dequeue is Empty"
        else:
            self.head.data = None
            self.head = self.head.next
            self.head.prev.next = None
            self.head.prev = None
            self.length -= 1

    def deleteRear(self):
        if (self.tail == None):
            return "Dequeue is Empty"
        else:
            self.tail.data = None
            self.tail = self.tail.prev
            self.tail.next.prev = None
            self.tail.next = None
            self.length -= 1

    def isEmpty(self):
        return (self.length == 0)

    def getFront(self):
        return self.head.data

    def getRear(self):
        return self.tail.data

    def getLength(self):
        return self.length

    def display(self):
        cur = self.head
        while cur != None:
            print(cur.data,end=" ")
            cur = cur.next
        print()


d = Dequeue()

for i in range(10):
    d.insertFront(i)

#inserts 1 at front => 1
#inserts 2 at front => 2, 1
#inserts 3 at front => 3, 2, 1
#.....
#inserts 9 at front => 9, 8, 7, 6, 5, 4, 3, 2, 1

d.display()
#output => 9 8 7 6 5 4 3 2 1 0

d.deleteRear()
#removes last element

d.display()
#output => 9 8 7 6 5 4 3 2 1
