class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, element):
        new_node = Node(data=element)

        if self.head is None:
            self.head = new_node
            return

        current_node = self.head
        while current_node.next is not None:
            current_node = current_node.next

        current_node.next = new_node

    def findLoop(self):
        hash_map = set()
        current_node = self.head
        while current_node is not None:
            if current_node in hash_map:
                return True

            hash_map.add(current_node)
            current_node = current_node.next

        return False

    def __repr__(self):
        all_nodes = []
        current_node = self.head
        while current_node is not None:
            all_nodes.append(str(current_node.data))
            current_node = current_node.next
        if len(all_nodes) > 0:
            return " -> ".join(all_nodes)
        else:
            return ""
