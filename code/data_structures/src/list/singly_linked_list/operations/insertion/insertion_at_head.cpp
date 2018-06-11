/*
  C++ program to add elements at the head of a Singly Linked List
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


// Function to add A node at the Head of the List
void insertAtHead(node **head,int data)
{
    node *newptr = new node;            //newptr to create new node
    newptr->data=data;
    newptr->next=*head;
    *head=newptr;                       //making the new node as head
}

int main()
{
    node *head = new node;
    int choice(0),first(1),data;            //first is to check if its the first Element of the List
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
            insertAtHead(&head,data);
        }
       cout<<"Do you want to add more Elements at HEAD?(0 for NO, 1 for YES)";
       cin>>choice;
    }
    printList(head);
}
