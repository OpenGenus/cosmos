#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

Node *findNode(Node* head, int search_for)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}


void insert()
{
    cout<<"Enter the total number of nodes to be inserted"<<endl;
    int n,i,value;
    Node *temp;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
	cout<<"Enter the data of node "<<(i+1)<<endl;
        scanf("%d",&value);
        if(i==0)
        {
            head=new Node(value);
            temp=head;
            continue;
        }
        else
        {
            temp->next= new Node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}

/* Function to print linked list */
void printList(Node *node)
{
    cout<<"The elements in the linked list after performing deletion are"<<endl;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
   // Your code here
   Node *current = head;
   while(current != NULL){
       if((node->data) == (current->data)){
           break;
       }
       current = current->next;
   }
   Node *previous = NULL;
   while(current->next != NULL){
       previous = current;
       current->data = current->next->data;
       current = current->next;
   }
   previous->next = NULL;
}


int main(void)
{
    /* Start with the empty list */

    int t,k,n,value;
    cout<<"Enter the number of test cases"<<endl;
    scanf("%d",&t);
    while(t--)
    {
        insert();
	cout<<"Enter the node to be deleted(except last node)"<<endl;
        scanf("%d",&k);
        Node *del = findNode(head, k);
        if (del != NULL && del->next != NULL)
        {
            deleteNode(del);
        }
        printList(head);
    }
    return(0);
}
