# What is Doubly Linkedlist 

In simple terms, Doubly linkedlist is version of single linkedlist having prev and next pointer connected to the respective position. Therefore, in a doubly linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer) , pointer to the previous node (previous pointer)
The prev part of the first node and the next part of the last node will always contain null indicating end in each direction.

# Difference between Single and Doubly Linkedlist

When compared with Single linkedlist, In a singly linked list, we could traverse only in one direction, because each node contains address of the next node and it doesn't have any record of its previous nodes. However, doubly linked list overcome this limitation of singly linked list. Due to the fact that, each node of the list contains the address of its previous node, we can find all the details about the previous node as well by using the previous address stored inside the previous part of each node.
Doubly linked list consumes more space for every node and therefore, causes more expansive basic operations such as insertion and deletion. However, we can easily manipulate the elements of the list since the list maintains pointers in both the directions.

In terms of Complexity, complexity of insertion and deletion at a known position is O(1) in doubly linkedlist as compared to o(n) in singly linkedlist.

# Disadvantages of Doubly Linkedlist

Every node of DLL Require extra space for an previous pointer.
All operations require an extra pointer previous to be maintained. For example, in insertion, we need to modify previous pointers together with next pointers.

# Psuedo Code

To implement DLL, 

struct node   
{  
    struct node *prev;   
    int data;  
    struct node *next;   
}   

