/*
  C program to add integer elements at the head of a Singly Linked List
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

// print the list given pointer to the head of the linked list
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


// insert a node with given data at the head of the linked list
// takes O(1) time
void insertAtHead(Node **head, int data)
{
    if (head == NULL) {
        printf("ERROR head input value is NULL\n"); 
	return;
    }

    Node *node = malloc(sizeof(Node)); // allocate new Node being added
    node->data = data; // initialze data field with given value
    node->next = *head; // insert the new node at the head of the list
    *head = node; // make new node the head of the list
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
        insertAtHead(&head, data[i]);
    }

    // print list after adding elements in data array
    printf("After inserting at head data values in following order: (");
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

    // test insertAtHead() error condition of passing Null head param value
    printf("Calling insertAtHead() with NULL head parameter raises:\n");
    insertAtHead(NULL, data[0]);
}
