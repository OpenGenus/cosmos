# Part of Cosmos by OpenGenus Foundation
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_next(self, new_next):
        self.next = new_next


class LinkedList:
    def __init__(self):
        self.head = None

    def size(self):
        cur_node = self.head
        length = 0
        while current_head != None:
            length += 1
            cur_node = current_head.get_next()
        return length

    def search(self, data):
        cur_node = self.head
        while cur_node != None:
            if cur_node.get_data() == data:
                return cur_node
            else:
                cur_node = cur_node.get_next()
        return None

    def delete(self, data):
        cur_node = self.head
        prev_node = None
        while cur_node != None:
            if cur_node.get_data() == data:
                if cur_node == self.head:
                    self.head = current.get_next()
                else:
                    next_node = current.get_next()
                    prev_node.set_next(next_node)
                return cur_node
            prev_node = cur_node
            cur_node = cur.get_next()
        return None

    def print_list(self):
        start = 1
        cur_node = self.head
        while cur_node != None:
            if start == 1:
                start = 0
            else:
                print("->"),
            print(cur_node.get_data()),
            cur_node = cur_node.get_next()

    def insert(self, data):
        new_node = Node(data)
        new_node.set_next(self.head)
        self.head = new_node
