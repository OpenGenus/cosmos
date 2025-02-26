/*
  C program to add integer elements at the tail of a Singly Linked List
  Part of Cosmos by OpenGenus Foundation
 */

#include <stdio.h>
#include <stdlib.h>

/*
  A node in a singly-linked list with fields:
  data - data stored in the node
  next - link to the next node
 */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// print the list give pointer to the head of the linked list
void printList(Node *head)
{
    if (head == NULL) {
        printf("Linked List is empty\n");
    } else {
        printf("Linked List:");
        while(head->next != NULL) {
	    printf(" %d ->", head->data);
	    head = head->next;
	}
        printf(" %d\n", head->data);
    }
}


// insert a node with given data at the tail of the linked list
// takes O(n) time
void insertAtTail(Node **head, int data)
{
    if (head == NULL) {
        printf("ERROR head input value is NULL\n"); 
	return;
    }

    Node *node = malloc(sizeof(Node)); // allocate new Node being added
    node->data = data; // initialze data field with given value
    node->next = NULL; // next is set to NULL since new node will be last node

    if (*head == NULL) { // list currently empty
    	*head = node; // first node inserted into the list
	return;
    }

    // find the last node of the current list
    Node *curr = *head;
    while (curr->next != NULL) {
    	curr = curr->next;
    }
    curr->next = node;
}

// delete all nodes in the list
Node *deleteList(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
	free(head);
	head = next;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    int data[] = {4, 7, 10, 1, 12, 2, 5}; // data values being added to list 
    int i;

    // test printing empty list
    printf("Before inserting: ");
    printList(head);

    for (i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        insertAtTail(&head, data[i]);
    }

    // print list after adding elements in data array
    printf("After inserting at tail data values in following order: (");
    for (i = 0; i < (sizeof(data) / sizeof(data[0]) - 1); i++) {
        printf("%d, ", data[i]);
    }
    printf("%d)\n", data[i]);
    printList(head);

    // delete list
    printf("After deleting all nodes: ");
    head = deleteList(head);

    // print to make sure the list has been deleted
    printList(head);

    // test insertAtTail() error condition of passing Null head param value
    printf("Calling insertAtTail() with NULL head parameter raises:\n");
    insertAtTail(NULL, data[0]);
}
