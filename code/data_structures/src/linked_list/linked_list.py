''' simple prpgrame for single linked list in python '''


class Node:
    '''

    This is class to create a node

    Attributes:
        :data: contains data element
        :link: points to the next Node

    '''

    def __init__(self, data, next=None):
        '''
        The constructor for Node class

        Parameters:
            :data: (required)
            :link: (optional)
        '''

        self.data = data
        self.next = next



class LinkedList:
    '''
    This is class to create a Linked List

    Attributes:
        :head: points to the starting node of Linked List

    '''

    def __init__(self):
        '''
        The constructor to LinkedList Class

        Parameter:
            :head: 
        '''

        self.head = None
        

    def insertAtEnding(self, data):
        '''
        The function to add the node at the end of Linked List

        Parameters:
            :data: (required)
        '''

        newNode = Node(data)
        if self.head == None:
            self.head == newNode
        else:
            current = self.head
            while current.next != None:
                current = current.next
            current.next = newNode


    def printLinkedList(self):
        '''
            The function to traverse and print the data elements present in each node
        '''

        if self.head == None:
            print("No Liked List exists")
        else:
            current = self.head
            while current != None:
                print(str(current.data), end=" --> ")
                current = current.next
            print("NULL")         



if __name__ == '__main__':
    list1 = LinkedList()            # Creating LinkedList Object
    list1.head = Node(2)            # Creating first node
    list1.insertAtEnding(6)
    list1.insertAtEnding(5)
    list1.insertAtEnding(10)
    list1.insertAtEnding(20)
    list1.printLinkedList()
