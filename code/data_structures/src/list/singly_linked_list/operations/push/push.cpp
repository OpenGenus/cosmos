#include <iostream>
using namespace std;

// Everytime you work with Append or Push function, there is a corner case.
// When a NULL Node is passed you have to return a Node that points to the given value.
// There are two ways to achieve this:
// 1. Receive the double pointer as an argument.
// 2. Return the new Node.

struct Node
{
    int data;
    Node* next;
};

void printList( Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void push( Node** headref, int x)
{
    Node* head = *headref;
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    *headref = newNode;
}


void pushAfter(Node* prev_Node, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = prev_Node->next;
    prev_Node->next = newNode;
}

void append( Node** headref, int x)
{
    Node* head = *headref;
    if (head == nullptr)
    {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        *headref = newNode;
        return;
    }
    while (head->next)
        head = head->next;
    Node *temp = new Node();
    head->next = temp;
    temp->data = x;
}

int main()
{
    Node *head = nullptr;
    append(&head, 5);
    append(&head, 10);
    push(&head, 2);
    pushAfter(head->next, 4);
    printList(head);
    return 0;
}
