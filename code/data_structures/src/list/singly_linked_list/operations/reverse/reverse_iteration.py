class Node():
    def __init__(self, value):
        self.data = value
        self.next = None

class Linkedlist():
    def __init__(self):
        self.head = None

    def insert_end(self,value):
        node = Node(value)
        if(self.head==None):
            self.head = node
        else:
            cur = self.head
            while(cur.next):
                cur = cur.next
            cur.next = node

    def insert_head(self,value):
        node = Node(value)
        if(self.head==None):
            self.head = node
        else:
            node.next = self.head
            self.head = node

    def traverse(self):
        if self.head == None:
            return None
        cur = self.head
        print('Elements are :', end=' ')
        while(cur):
            print(cur.data,end=' ')
            cur = cur.next
        print()


########################################################################
    def reverse(self):
        if self.head == None or self.head.next == None:
            return
        head = self.head
        tail = None
        while(head):
            temp = head.next
            head.next = tail
            tail = head
            head = temp
        self.head = tail

#################################################################3

lis = Linkedlist()
lis.insert_head(1)
lis.insert_head(2)
lis.insert_head(3)
lis.insert_head(4)
lis.insert_end(5)
lis.insert_end(6)
lis.insert_end(7)
print('Given list is : ',end="")
lis.traverse()
lis.reverse()
print('Reversed list is : ',end="")
lis.traverse()
