/*
  C++ program to insert element at the nth position of a Singly Linked List
  Part of Cosmos by OpenGenus Foundation
 */
#include<iostream>
#include<cstdlib>

using namespace std;


struct node{
             int data;
             node *next;

            };

void printList(node *head)
{
    cout<<"This is your current List\n";
    while(head!=NULL)
    {
        cout<<head->data<<" => ";
        head=head->next;
    }
    cout<<"NULL\n";
}

void insertAtTail(node **head,int data)
{
    node *newptr = new node;
    newptr->data=data;
    newptr->next=NULL;

    node *dummy = *head;
    while(dummy->next!=NULL) dummy=dummy->next;
    dummy->next = newptr;
    return;
}

//function to insert node at nth position of the Linked List
void insertAtPosition(node **head,int position,int data)
{
    node *newptr=new node;
    newptr->data=data;

    node *dummy = *head;                //dummy variable is used to traverse to the required position
    node *prev = dummy;                 //prev node to keep track of the previous node

    while(--position)                   //loop to traverse to the required position
    {
        prev=dummy;
        dummy=dummy->next;
    }
    prev->next=newptr;
    newptr->next=dummy;
}

int main()
{
    node *head = new node;
    int choice(0),first(1),data;            //first is to check if its the first item of the List
    cout<<"List is currently empty. Press 1 to add an Element\n";
    cin>>choice;
    while(choice)
    {
        if(first==1){
            cout<<"\nEnter the Data Element\n";
            cin>>head->data;
            head->next=NULL;
            first=0;
        }
        else{
            cout<<"\nEnter the Data Element\n";
            cin>>data;
            insertAtTail(&head,data);
        }
       cout<<"Do you want to add more Elements at the TAIL?(0 for NO, 1 for YES)";
       cin>>choice;
    }
    printList(head);

    cout<<"\nDo you want to add an Element at a certain Position?(0 for NO, 1 for YES)\n";
    cin>>choice;
    if(choice==1)
    {
        int position;
        cout<<"\nEnter the Position where new Element is to be inserted";
        cin>>position;
        cout<<"\nEnter the Data";
        cin>>data;
        insertAtPosition(&head,position,data);
    }
    printList(head);
}


