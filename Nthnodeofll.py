# Python program to find n'th node from end using slow
# and fast pointer

# Node class 
class Node:

    # Constructor to initialize the node object
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:

    # Function to initialize head
    def __init__(self):
        self.head = None

    # Function to insert a new node at the beginning
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def printNthFromLast(self, n):
        main_ptr = self.head
        ref_ptr = self.head 
    
        count  = 0 
        if(self.head is not None):
            while(count < n ):
                if(ref_ptr is None):
                    print "%d is greater than the no. pf \
                            nodes in list" %(n)
                    return
 
                ref_ptr = ref_ptr.next
                count += 1

        while(ref_ptr is not None):
            main_ptr = main_ptr.next 
            ref_ptr = ref_ptr.next

        print "Node no. %d from last is %d " %(n, main_ptr.data)


# Driver program to test above function
llist = LinkedList()
llist.push(20)
llist.push(4)
llist.push(15)
llist.push(35)

llist.printNthFromLast(4)

# This code is contributed by Nikhil Kumar Singh(nickzuck_007)
