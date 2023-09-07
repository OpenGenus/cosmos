/*
  C program to add integer elements at the nth position of a Singly Linked List
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

/*
  Insert a node with given data at the nth position of the linked list.
  Position index is zero based, i.e. first node is at position 0
  If n > number of nodes in linked list then data added at tail of the list
  Takes O(n) time
*/
void insertAtPosition(Node **head, int data, int n)
{
    if (head == NULL || n < 0) {
        if (head == NULL)
	    printf("ERROR head input value is NULL\n"); 
	else
	    printf("ERROR given position index = %d is less than 0\n", n);
	return;
    }

    Node *node = malloc(sizeof(Node)); // allocate new Node being added
    node->data = data; // initialze data field with given value
    node->next = NULL; // next is set to NULL as new node may be added to tail

    if (*head == NULL) { // list currently empty
    	*head = node; // first node inserted into the list
	return;
    }

    // find the nth node of the current list
    Node *prev = NULL;
    Node *curr = *head;
    int i;
    for (i = 0; curr->next != NULL && i != n; i++) {
	prev = curr;
    	curr = curr->next;
    }

    if (i != n) { // n > size of linked list
        curr->next = node; // new node is added at the tail of the list
    } else { // found nth position
        node->next = curr;
	if (prev == NULL) {
	    // node is the new head
	    *head = node;
	} else {
	    prev->next = node;
	}
    }
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

    // test inserting at position 5 of an empty linked list
    printf("Test insert into empty linked list data value 4 at position 5\n");
    insertAtPosition(&head, data[0], 5);
    printList(head);

    // delete list
    printf("After deleting all nodes: ");
    head = deleteList(head);
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

    printf("\n*** NOTE: Position index is zero-based starting at index 0\n\n");

    // test inserting at position 0 
    printf("Test inserting at position 0 node with data value 200\n");
    insertAtPosition(&head, 200, 0);
    printList(head);

    // test inserting at position 4 
    printf("Test inserting at position 4 node with data value 444\n");
    insertAtPosition(&head, 444, 4);
    printList(head);

    // test inserting at position 8 
    printf("Test inserting at position 8 node with data value 888\n");
    insertAtPosition(&head, 888, 8);
    printList(head);

    // test inserting at position 20 
    printf("Test inserting at position 20 node with data value 2222\n");
    insertAtPosition(&head, 2222, 20);
    printList(head);

    // delete list
    printf("After deleting all nodes: ");
    head = deleteList(head);

    // print to make sure the list has been deleted
    printList(head);

    // test insertAtPosition() error condition of passing Null head param value
    printf("Calling insertAtPosition() with NULL head parameter raises:\n");
    insertAtPosition(NULL, data[0], 0);

    // test insertAtPosition() error by passing negative position index
    printf("Calling insertAtPosition() with negative position index raises:\n");
    insertAtPosition(&head, data[0], -1);

}
