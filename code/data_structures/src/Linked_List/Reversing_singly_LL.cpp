#include "bits/stdc++.h"
using namespace std;

//creating a class Node for Linked List
class Node
{
    public:
        int data;
        Node* next;

        //constructor declaration
        Node(int data)
        {
            this->data=data;
            this->next=NULL;
        }
};

//Taking reference by call to change the original Linked List and reverse it

void reverseList(Node* &head) 
{
    Node* prev = NULL;
    Node* forw = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    head=prev;
}

//insertion of a node at the tail of the Linked list
void insertAtTail(Node* &tail, int data)
{
    Node *temp =new Node(data);
    tail->next=temp;
    tail=temp;

}

//printing out the linked list
void print(Node * &head)
{
    Node * temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;
}

int main()
{
    Node * node1=new Node(0);

    Node *head =node1;
    Node* tail=node1;

    insertAtTail(tail,1);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,6);

    cout<<"Before reversing: ";
    print(head);

    reverseList(head);

    cout<<"After reversing: ";
    print(head);
    
    return 0;
}