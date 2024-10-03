import collections


class LinkedList(collections.Iterable):
    class Node(object):
        def __init__(self, data, next=None):
            super(LinkedList.Node, self).__init__()
            self.data = data
            self.next = next

    class LinkedListIterator(collections.Iterator):
        def __init__(self, head):
            self._cur = head

        def __iter__(self):
            return self

        def next(self):
            if self._cur is None:
                raise StopIteration

            retval = self._cur
            self._cur = self._cur.next

            return retval

    def __init__(self):
        super(LinkedList, self).__init__()
        self.head = None

    def __iter__(self):
        it = LinkedList.LinkedListIterator(self.head)
        return iter(it)

    def add(self, data):
        # add new node to head of list
        new = LinkedList.Node(data, self.head)
        self.head = new
        return new

    def add_node(self, node):
        node.next = self.head
        self.head = node
        return node

    def rm(self, node):
        # del node from list
        it = iter(self)
        prev = self.head
        try:
            while True:
                n = it.next()
                if n is node:
                    if n is self.head:
                        self.head = self.head.next
                    else:
                        prev.next = n.next
                    return
                prev = n
        except StopIteration:
            raise KeyError

    def has_loop(self):
        class Skip2Iterator(LinkedList.LinkedListIterator):
            def next(self):
                super(Skip2Iterator, self).next()
                return super(Skip2Iterator, self).next()

        it = LinkedList.LinkedListIterator(self.head)
        it2 = Skip2Iterator(self.head)
        try:
            while True:
                n1 = it.next()
                n2 = it2.next()
                if n1 is n2:
                    return True
        except StopIteration:
            return False
