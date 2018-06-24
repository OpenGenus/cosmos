class Node:
    '''
    A Node in a singly-linked list

    Parameters
    -------------------
    data :
        The data to be stored in the node
    next:
        The link to the next node in the singly-linked list
    '''

    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def __repr__(self):
        ''' Node representation as required'''
        return (self.data)


class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        '''
        Inserts New data at the ending of the Linked List
        Takes O(n) time
        '''
        new_node = Node(data=data)
        if not self.head:
            self.head = new_node
            return

        current_node = self.head
        while current_node.next is not None:
            current_node = current_node.next

        current_node.next = new_node

    def find(self, data):
        '''
        Returns the first index at which the element is found
        Returns -1 if not found
        Takes O(n) time
        '''

        if self.head is not None:
            current_node = self.head
            index = 0
            while current_node.next is not None:
                if current_node.data = data:
                    return index
                index += 1
        return -1

    def __repr__(self):
        '''
        Gives a string representation of the list in the
        given format:
        a -> b -> c -> d
        '''
        all_nodes = []
        current_node = self.head
        while current_node:
            all_nodes.append(str(current_node.data))
            current_node = current_node.next
        if len(all_nodes) > 0:
            return ' -> '.join(all_nodes)
        else:
            return ""
