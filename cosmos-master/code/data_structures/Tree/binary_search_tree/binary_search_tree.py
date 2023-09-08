class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.head = None

    def Insert(self, value):
        temp = node(value)

        if(self.head == None):
            self.head = temp
        else:
            current = self.head

            while current != None:
                if value < current.data:
                    if current.left != None:
                        current = current.left
                    else:
                        current.left = temp
                        return
                else:
                    if current.right != None:
                        current = current.right
                    else:
                        current.right = temp
                        return

    def Search(self, value):
        current = self.head

        while current != None:
            if value < current.data:
                current = current.left
            elif value > current.data:
                current = current.right
            else:
                print("Element " + str(value) + " Found")
                return

        print("Element " + str(value) + " not Found")

    def Min_Value(self, head):
        while head.left != None:
            head = head.left

        return head.data

    def Delete_Key(self, head, value):
        if head == None:
            return head

        if value < head.data:
            head.left = self.Delete_Key(head.left, value)
        elif value > head.data:
            head.right = self.Delete_Key(head.right, value)
        else:
            if head.right == None:
                return head.left
            elif head.left == None:
                return head.right

            head.data = self.Min_Value(head.right)
            head.right = self.Delete_Key(head.right, head.data)

        return head

    def Delete(self, value):
        self.head = self.Delete_Key(self.head, value)

BST = BinarySearchTree()
