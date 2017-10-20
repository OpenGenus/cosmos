// C++ program to print reverse of a linked list
#include <iostream>

struct Node {
    int data;
    struct Node *next;
};

void printReverse(struct Node *head) {
    if (head == nullptr) { return; }
    printReverse(head->next);
    std::cout<<head->data<<" ";
}

void push(struct Node **head_ref, char new_data) {
    auto new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node *head = nullptr;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printReverse(head);
    return 0;
}
