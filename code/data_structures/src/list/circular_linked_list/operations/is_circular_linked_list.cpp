#include <iostream>
using namespace std;
//node structure
struct node{
    int data;
    struct node* next;
};
//function to find the circular linked list.
bool isCircular(node *head){
    node *temp=head;
    while(temp!=NULL)
    { //if temp points to head then it has completed a circle,thus a circular linked list.
        if(temp->next==head)
            return true;
        temp=temp->next;
    }

    return false;

}
//function for inserting new nodes.
node *newNode(int data){
    struct node *temp=new node;
    temp->data=data;
    temp->next=NULL;
}
int main() {
    //first case
    struct node* head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);
    head->next->next->next->next=head;
    if(isCircular(head))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    //second case
    struct node* head1=newNode(1);
    head1->next=newNode(2);

    if(isCircular(head1))
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}



