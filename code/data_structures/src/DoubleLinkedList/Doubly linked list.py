class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
class DLL:
    def __init__(self):
        self.ptr = None
    def Insert(self, data):
        if self.ptr == None:
            self.ptr = Node(data)
        else:
            newnode = Node(data)
            current = self.ptr
            prev = None
            nextptr = current.next
            while current.data < newnode.data and current != None:
                prev = current
                current = current.next
                if current == None:
                    break
            if current == None:
                prev.next = newnode
                newnode.prev = prev
            elif prev == None:
                newnode.next = self.ptr
                self.ptr = newnode
            else:
                prev.next = newnode
                newnode.next = current
                newnode.prev = prev
                current.prev = newnode
    def Display(self):
        temp = self.ptr
        while temp:
            print(temp.data, end="<->")
            temp = temp.next
        print("Null")
    def Delete(self, data):
        if self.ptr == None:
            print("List is Empty")
            return
        else:
            current = self.ptr
            prev = None
            while current.data != data and current != None:
                prev = current
                current = current.next
                if current == None:
                    print("Item not found in List")
                    return
            if prev == None:
                self.ptr = current.next
                current.prev = self.ptr
            else:
                prev.next = current.next
                current.prev = prev.next
    def Empty(self):
        return self.ptr == None
    def HasCycle(self):
        slow = self.ptr
        fast = self.ptr
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False
dll = DLL()
while True:
    choice = int(input("\n1.Insert\n2.Delete\n3.Check Empty\n4.Detect Cycle\n5.Exit\nEnter Choice : "))
    if choice == 1:
        value = int(input("Enter element to Insert : "))
        dll.Insert(value)
        dll.Display()
    elif choice == 2:
        value = int(input("Enter element to Delete : "))
        dll.Delete(value)
        dll.Display()
    elif choice == 3:
        print(dll.Empty())
    elif choice == 4:
        if dll.HasCycle():
            print("Cycle detected in the linked list")
        else:
            print("No cycle detected in the linked list")
    elif choice == 5:
        break
print("Program End")
