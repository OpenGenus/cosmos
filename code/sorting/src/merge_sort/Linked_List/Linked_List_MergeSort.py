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

    # creates a new node with given value and appends it at the end of the linked list

    def merge(self, l1, l2): 
        head = None
          
        # Base cases
        if l1 == None: 
            return l2 

        if l2 == None: 
            return l1
              
        # pick either l1 or l2 and recurse 
        if l1.data <= l2.data: 
            head = l1 
            l1 = l1.next
        else: 
            head = l2 
            l2 = l2.next

        ptr=head
    
        while l1!=None and l2!=None:
            
            if l1.data<l2.data:
                ptr.next = l1
                l1 = l1.next
            else:
                ptr.next = l2
                l2 = l2.next

            ptr = ptr.next
    
        if l1 != None:
            ptr.next = l1
        else:
            ptr.next = l2
        
        return head


    def mergeSort(self, head):

        if head == None or head.next == None:
            return head

        ptr1 = head
        ptr2 = head.next

        while(ptr2 != None and ptr2.next != None):
            ptr1 = ptr1.next
            if ptr2.next != None:
                ptr2 = ptr2.next.next

        ptr2 = ptr1.next
        ptr1.next = None

        return self.merge(self.mergeSort(head), self.mergeSort(ptr2))


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
        
        li.head = li.mergeSort(li.head)
        printList(li.head)
