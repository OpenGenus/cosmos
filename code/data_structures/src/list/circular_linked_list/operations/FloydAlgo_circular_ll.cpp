#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
bool isCircular(node *head)
{ //fast ptr is ahead of slow pointer
    node* slow,*fast;
    slow=head;
    fast=head->next;
    //if linked list is empty it returns true as its entirely null.
    if(head==NULL)
        return true;
    while(true)
    { //fast ptr traverses quickly so If its not circular then it reaches or points to null.
        if(fast==NULL||fast->next==NULL)
        {
            return false;
        }
            //when circular fast meets or points to slow pointer while traversing
        else if(slow==fast||fast->next==slow)
        {
            return true;
        }
            //for moving forward through linked list.
        else
        {
            slow=slow->next;
            //fast traverses way ahead so it distinguishes loops out of circular list.
            fast=fast->next->next;
        }
    }
}

node *newNode(int data){
    struct node *temp=new node;
    temp->data=data;
    temp->next=NULL;
}
int main() {
    struct node* head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(12);
    head->next->next->next=newNode(122);
    head->next->next->next->next=head;
    if(isCircular(head))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    struct node* head1=newNode(1);
    head1->next=newNode(2);
    head1->next->next=newNode(3);
    head1->next->next->next=newNode(7);

    if(isCircular(head1))
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}

