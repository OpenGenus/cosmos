/*
  C++ program to add elements at the head of a Singly Linked List
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


// Function to add A node at the Head of the List
void insertAtHead(node **head,int data)
{
    if(*head==NULL){
        (*head)->data=data;
        return;
    }

    node *newptr = new node;            //newptr to create new node
    newptr->data=data;
    newptr->next=*head;
    *head=newptr;                       //making the new node as head
}

int main()
{
    node *head = new node;
    int choice(0),first(1),data;            //first is to check if its the first Element of the List
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
            insertAtHead(&head,data);
        }
       std::cout<<"Do you want to add more Elements at HEAD?(0 for NO, 1 for YES)";
       std::cin>>choice;
    }
    printList(head);
}
