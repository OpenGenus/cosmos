# Python Utility to add element at the end of the Singly Linked List
# Part of Cosmos by OpenGenus Foundation


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
        ''' Initializes node structure'''
        self.data = data
        self.next = next

    def __repr__(self):
        ''' Node representation as required'''
        return (self.data)


class SinglyLinkedList:
    '''
    A structure of singly linked lists
    '''

    def __init__(self):
        '''Creates a Singly Linked List in O(1) Time'''
        self.head = None

    def append(self, data):
        '''
        Inserts New data at the ending of the Linked List
        Takes O(n) time
        '''
        if not self.head:
            self.head = Node(data=data)
            return

        current_node = self.head
        while current_node.next:
            current_node = current_node.next

        new_node = Node(data=data, next=None)
        current_node.next = new_node

    def find(self, data):
        if self.head is None:
            return 'Linked List is Empty'
        current_node = self.head
        node_indices = []
        counter = 0
        while current_node:
            if current_node.data = data:
                node_indices.append(counter)
            counter += 1
        if len(node_indices > 0):
            return str(Indexes where requested data was found were :)+str(*node_indices)
        else:
            return 'Requested data not found in Linked List'

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
            return 'Linked List is empty'
