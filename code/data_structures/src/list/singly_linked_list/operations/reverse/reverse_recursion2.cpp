#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void printReverse(struct Node* head)
{
    if (head == NULL)
        return;
    printReverse(head->next);
    cout << head->data << " ";
}

void push(struct Node** head_ref, char new_data)
{
    struct Node* new_node = new Node;

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

int main()
{
    struct Node* head = NULL;
    for (int i = 0; i < 10; i++)
        push(&head, i);

    printReverse(head);
    return 0;
}
