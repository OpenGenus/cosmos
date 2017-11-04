#include <bits/stdc++.h>
using namespace std;

//Append or Push function k saath khelne mai hamesha ek ye corner case hoga that in case the element passed is NULL, then you have to essentially add a node and return. There are two ways you can do, if you receive the double pointer as an argument or if you are returning node.


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
    node *head =NULL;
    append(&head, 5);
    append(&head, 10);
    printList(head);

    return 0;
}
