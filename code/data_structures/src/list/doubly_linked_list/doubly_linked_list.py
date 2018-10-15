# Part of Cosmos by OpenGenus Foundation
class DoublyLinkedList:
    class Node:
        def __init__(self, data, prevNode, nextNode):
            self.data = data
            self.prevNode = prevNode
            self.nextNode = nextNode

    def __init__(self, data=None):
        self.first = None
        self.last = None
        self.count = 0

    def addFirst(self, data):
        if self.count == 0:
            self.first = self.Node(data, None, None)
            self.last = self.first
        elif self.count > 0:
            # create a new node pointing to self.first
            node = self.Node(data, None, self.first)
            # have self.first point back to the new node
            self.first.prevNode = node
            # finally point to the new node as the self.first
            self.first = node
        self.current = self.first
        self.count += 1

    def popFirst(self):
        if self.count == 0:
            raise RuntimeError("Cannot pop from an empty linked list")
        result = self.first.data
        if self.count == 1:
            self.first = None
            self.last = None
        else:
            self.first = self.first.nextNode
            self.first.prevNode = None
        self.current = self.first
        self.count -= 1
        return result

    def popLast(self):
        if self.count == 0:
            raise RuntimeError("Cannot pop from an empty linked list")
        result = self.last.data
        if self.count == 1:
            self.first = None
            self.last = None
        else:
            self.last = self.last.prevNode
            self.last.nextNode = None
        self.count -= 1
        return result

    def addLast(self, data):
        if self.count == 0:
            self.addFirst(0)
        else:
            self.last.nextNode = self.Node(data, self.last, None)
            self.last = self.last.nextNode
            self.count += 1

    def __repr__(self):
        result = ""
        if self.count == 0:
            return "..."
        cursor = self.first
        for i in range(self.count):
            result += "{}".format(cursor.data)
            cursor = cursor.nextNode
            if cursor is not None:
                result += " --- "
        return result

    def __iter__(self):
        # lets Python know this class is iterable
        return self

    def __next__(self):
        # provides things iterating over class with next element
        if self.current is None:
            # allows us to re-iterate
            self.current = self.first
            raise StopIteration
        else:
            result = self.current.data
            self.current = self.current.nextNode
            return result

    def __len__(self):
        return self.count


dll = DoublyLinkedList()
dll.addFirst("days")
dll.addFirst("dog")
dll.addLast("of summer")

assert list(dll) == ["dog", "days", "of summer"]
assert dll.popFirst() == "dog"
assert list(dll) == ["days", "of summer"]
assert dll.popLast() == "of summer"
assert list(dll) == ["days"]
