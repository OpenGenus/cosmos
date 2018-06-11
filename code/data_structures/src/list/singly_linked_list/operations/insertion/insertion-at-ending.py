#Python Utility to add element at the end of the Singly Linked List
#Part of Cosmos by OpenGenus Foundation

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

class Singly_Linked_List:
    '''
    A structure of singly linked lists
    '''

    def __init__(self):
        '''Creates a Singly Linked List in O(1) Time'''
        self.head = None
    
    def Insert_In_End(self,data):
        '''
        Inserts New data at the ending of the Linked List
        Takes O(n) time
        '''
        if not self.head:
            self.head=Node(data=data)
            return
        
        current_node = self.head
        while current_node.next:
            current_node = current_node.next

        NewNode=Node(data=data,next=None)
        current_node.next = NewNode

    def __repr__(self):
        '''
        Gives a string representation of the list in the
        given format:

        a -> b -> c -> d
        '''
        AllNodes = []
        current_node = self.head
        while current_node:
            AllNodes.append(str(current_node.data))
            current_node = current_node.next
        if len(AllNodes) > 0:
            return ' -> '.join(AllNodes)
        else:
            return 'Linked List is empty'
            
        
        
    
    
