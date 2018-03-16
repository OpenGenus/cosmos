#include <iostream>

// Part of Cosmos by OpenGenus Foundation
struct Node
{
    Node *nextNode;
    int data;

    Node() //constructor
    {
        nextNode = nullptr;
        data = 0;
    }
};

// Singly Linked List
class LinkedList
{
    public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }
};

// Add a Node to the end of a linked list
void push(LinkedList *list, int value)
{
    if (list->head == NULL) 
    {
        list->head = new Node;
        list->head->data = value;
    }
    else
    {
        Node *currentNode = new Node;
        currentNode = list->head;
        while (currentNode->nextNode != NULL) 
            currentNode = currentNode->nextNode;
        currentNode->nextNode = new Node;
	currentNode->nextNode->data = value;
    }
}

// Return true if an element is found within a linked list
// otherwise return false
bool find(LinkedList *list, int value)
{
    Node *currentNode = new Node;
    currentNode = list->head;
    while (currentNode)
    {
        if (currentNode->data == value)
            return true;
        currentNode = currentNode->nextNode;
    }
    return false;
}

int main()
{
    // Create linked list
    LinkedList list; 
    // Push in elements
    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    push(&list, 4);
    push(&list, 5);
    push(&list, 6);
    // Find elements
    std::cout << find(&list, 1) << "\n";  // Should be 1 - True
    std::cout << find(&list, 3) << "\n";  // Should be 1 - True	
    std::cout << find(&list, 6) << "\n";  // Should be 1 - True
    std::cout << find(&list, 10) << "\n"; // Should be 0 - False
    std::cout << find(&list, 0) << "\n";  // Should be 0 - False	
}
