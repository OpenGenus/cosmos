/*
  C++ program to insert element at the nth position of a Singly Linked List
  Part of Cosmos by OpenGenus Foundation
 */
#include<iostream>
#include<cstdlib>


struct node{
             int data;
             node *next;

            };

void printList(node *head)
{
    std::cout<<"This is your current List\n";
    while(head!=NULL)
    {
        std::cout<<head->data<<" => ";
        head=head->next;
    }
    std::cout<<"NULL\n";
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
    int choice(0),first(1),data;
    int length=0;           //first is to check if its the first item of the List
    std::cout<<"List is currently empty. Press 1 to add an Element\n";
    std::cin>>choice;
    while(choice)
    {
        if(first==1){
            std::cout<<"\nEnter the Data Element\n";
            std::cin>>head->data;
            head->next=NULL;
            first=0;
            length++;
        }
        else{
            std::cout<<"\nEnter the Data Element\n";
            std::cin>>data;
            insertAtTail(&head,data);
            length++;
        }
       std::cout<<"Do you want to add more Elements at the TAIL?(0 for NO, 1 for YES)";
       std::cin>>choice;
    }
    printList(head);

    std::cout<<"\nDo you want to add an Element at a certain Position?(0 for NO, 1 for YES)\n";
    std::cin>>choice;
    if(choice==1)
    {
        int position;
        std::cout<<"\nEnter the Position where new Element is to be inserted";
        std::cin>>position;
        if(position>=0 && position<=length+1){
            std::cout<<"\nEnter the Data";
            std::cin>>data;
            insertAtPosition(&head,position,data);
            length++;
        }
        else{
            std::cout<<"Postion entered is not valid;No Element added.";
        }
    }
    printList(head);
}


