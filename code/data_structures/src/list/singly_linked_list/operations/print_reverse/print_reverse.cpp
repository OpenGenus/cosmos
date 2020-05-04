#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};

/* Function to push nodes in a linked list. */
void push(struct node **head_ref, int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}
 
/* Function to reverse the nodes in a linked list. */
void reverse(struct node **head_ref) {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}

/* Function to print the nodes in a linked list. */
void printnodes(struct node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

/* Driver function to check the above algorithm. */
int main() {
    struct node *head = NULL;
    push(&head, 10);
    push(&head, 11);
    push(&head, 18);
    push(&head, 60);
    push(&head, 94);
    push(&head, 100);
    cout << "List before reversing" << endl;
    printnodes(head);
    reverse(&head);
    cout << endl;
    cout << "List after reversing"<<endl;
    printnodes(head);
    return 0;
}
