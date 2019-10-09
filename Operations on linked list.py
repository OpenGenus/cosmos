class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def linearSearch(head, n):
    i=0
    while head is not None:
        
        if head.data==n:
            return i
        head=head.next
        i+=1
    return -1
    pass

def ll(arr):
    if len(arr)==0:
        return None
    head = Node(arr[0])
    last = head
    for data in arr[1:]:
        last.next = Node(data)
        last = last.next
    return head
def findtail(head):
    while head is not None:
        if head.data==-1:
            head=None
        tail=head
        head=head.next
    
    return tail
    
def append_LinkedList(head,n) :
    
    tail=findtail(head)
    curr=head
    if n==-1:
         return None
    for i in range(n-1):
        curr=curr.next
    h2=curr.next
    
    curr.next=None
    tail.next=head
    
    return h2

def eliminate_duplicate(head):
    
    if head==None or head.next==None:
        return head
    curr=head
    x=curr.next 
    while x is not None:
        while x.data==curr.data :
            x=x.next
            if x is None:
                break
            
        if x is None:
            curr.next=x
        else:
            curr.next=x
            x=x.next
            curr=curr.next
        
        return head
def length(head):
    c=0
    while head is not None:
        c+=1
        head=head.next
    return c 
def print_linkedlist_spl(head):
    #  Print a given linked list in reverse order. You need to print the tail
    #  first and head last. You can’t change any pointer in the linked list, just
    #  print it in reverse order.
    #  GOOD PROBLEM for RECURSION
    #############################
    # PLEASE ADD YOUR CODE HERE #
    #############################
    l=length(head)
    
    if l==1:
        print(head.data,end=" ")
        return head
    print_linkedlist_spl(head.next)
    print(head.data,end=" ")
    
    return head

def check_palindrome(head) :
    
    l=length(head)
    curr=head
    t=curr
    c=0
    if l==2:
        f=head.next
        if f.data==head.data:
            return True
    while c<(l//2):
        i=l
        t=head
        while i>c+1:
            t=t.next
            i-=1
        c+=1
        if curr.data!=t.data:
            return
        curr=curr.next
    return True

# Main
# Read the link list elements including -1
arr=list(int(i) for i in input().strip().split(' '))
# Create a Linked list after removing -1 from list
l = ll(arr[:-1])
data=int(input())
index = linearSearch(l, data)
print(index)
l = append_LinkedList(l,l1-i-1)
printll(l)
l = ll(arr[:-1])
l = eliminate_duplicate(l)
printll(l)
l = ll(arr[:-1])
print_linkedlist_spl(l)
l = ll(arr[:-1])
ans = check_palindrome(l)
if ans:
    print("true")
else:
    print("false")
