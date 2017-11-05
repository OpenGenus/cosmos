#include<iostream>
using namespace std;

// Eveerytime you work with Append or Push function, there is a corner case. That when a NULL node is passed you have to return a node that points to the given value. There are two ways you can do, if you receive the double pointer as an argument or if you are returning node.

struct node{
    int data;
    struct node* next;
};

void printList(struct node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void push(struct node** headref, int x){
    struct node* head = *headref;
    struct node* newNode = new node();
    newNode->data = x;
    newNode->next = head;
    *headref = newNode;
}


void pushAfter(struct node* prev_node, int data){
    struct node* newNode= new node();
    newNode->data =data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

void append(struct node** headref, int x){
    node* head = *headref;
    if(head==NULL){
        struct node* newNode = new node();
        newNode->data = x;
        newNode->next = NULL;
        *headref= newNode;
        return;
    }
    while(head->next){
        head= head->next;
    }
    node *temp = new node();
    head->next = temp;
    temp->data = x;
}

int main(){
    node *head =nullptr;
    append(&head, 5);
    append(&head, 10);
    push(&head, 2);
    pushAfter(head->next, 4);
    printList(head);
    return 0;
}
