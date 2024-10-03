import atexit
import io
import sys

class Node:
    
    def __init__(self, data): 
        self.data = data
        self.next = None

# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None

    def swap(self, ptr1, ptr2):
        temp = ptr1.data
        ptr1.data = ptr2.data
        ptr2.data = temp


    def selectionSort(self, head):

        if head==None:
            return

        ptr1=head

        while ptr1!=None:
            minimum = ptr1        # Initial the current node as minimum node
            ptr2 = ptrt1.next

            # Traverse for the unsorted part of the linked list 
            
            while ptr2!=None:
                if minimum.data > ptr2.data:
                    minimum = ptr2

                ptr2 = ptr2.next

            # Swap the minimum element with the current element
            swap(ptr1,minimum)
            ptr1 = ptr1.next


# prints the elements of linked list starting with head
def printList(head):
        
    if head is None:
        return
        
    temp = head
        
    while temp:
        print(temp.data,end="-->")
        temp = temp.next

    print("NULL")

'''
Sample Input
1 - Test cases
5 - Total number of elements to be inserted in linked list
23 2 34 5 1 - Adding the contents of the linked list

Sample Output
1 2 5 23 34
'''

if __name__ == '__main__':
    t=int(input())
        
    for cases in range(t):
        n = int(input())
        li = LinkedList()

        temp = li.head

        while n!=0:
            ele = int(input())
            ptr = Node(ele)

            if li.head is None:
                li.head = ptr
            else:
                temp.next = ptr

            temp = ptr
            n -= 1
        
        li.selectionSort(li.head)
        printList(li.head)
