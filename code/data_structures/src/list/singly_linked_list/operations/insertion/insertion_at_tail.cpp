/*
  C++ program to add elements at the Tail of a Singly Linked List
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

    node *dummy = *head;                    //dummy variables is used to traverse to the end of the List

    while(dummy->next!=NULL) dummy=dummy->next; //traversing to the last Element of the List
    dummy->next = newptr;                       //pointing the last Element to the new node
    return;
}

int main()
{
    node *head = new node;
    int choice(0),first(1),data;            //first is to check if its the first item of the List
    std::cout<<"List is currently empty. Press 1 to add an Element\n";
    std::cin>>choice;
    while(choice)
    {
        if(first==1){
            std::cout<<"\nEnter the Data Element\n";
            std::cin>>head->data;
            head->next=NULL;
            first=0;
        }
        else{
            std::cout<<"\nEnter the Data Element\n";
            std::cin>>data;
            insertAtTail(&head,data);
        }
       std::cout<<"Do you want to add more Elements at the TAIL?(0 for NO, 1 for YES)";
       std::cin>>choice;
    }
    printList(head);
}

