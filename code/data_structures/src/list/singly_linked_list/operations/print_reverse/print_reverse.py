# Part of Cosmos by OpenGenus Foundation
class Node(object):
    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node

    size = 0


def returnsize(root):
    i = 0
    while root:
        root = root.next_node
        i += 1
    return i


def insertatbeg(d, root):
    newnode = Node(d, None)
    if root:
        newnode.next_node = root
        root.size += 1
    return newnode


def insertatend(d, root):
    pre = root
    newnode = Node(d, None)
    if root:
        root.size += 1

        i = 0
        while root:
            pre = root
            root = root.next_node

            i += 1
        pre.next_node = newnode
    else:
        root = newnode


root = insertatbeg(910, None)

root = insertatbeg(90, root)
root = insertatbeg(80, root)
insertatend(2, root)
insertatend(27, root)
insertatend(17, root)
insertatend(37, root)
insertatend(47, root)
insertatend(57, root)
root = insertatbeg(90, root)
root = insertatbeg(80, root)
insertatend(47, root)
insertatend(57, root)

print(returnsize(root))
print(root.size)


def printlinklist(root):
    while root:
        print(root.data, end="  ")
        root = root.next_node


def printlinklist_in_reverse_order(root):
    if root != None:

        printlinklist_in_reverse_order(root.next_node)
        print(root.data, end=" ")


printlinklist(root)
print()
printlinklist_in_reverse_order(root)
