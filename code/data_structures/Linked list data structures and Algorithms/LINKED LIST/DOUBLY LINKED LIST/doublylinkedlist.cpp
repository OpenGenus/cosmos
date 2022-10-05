// DOUBLY Linked List -->Love Babbar
// topics -->
/*
1) Insert at head
2) Insert at tail
3)  Insert at middle
4)  Insert at any Position
5)  Deletion Operation of Node by position
6)  Deletion of node by value
*/

#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node*next;
node*prev;
node(int data){
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
}
~node(){
    int value=this->data;
    if(this->prev==NULL && this->next==NULL)
    {
        delete next;
        delete prev;
    }
}
};
void print(node*&head){
    node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp->prev=temp;
        head->prev=temp;
        temp=temp->next;
    }
    cout<<endl;
}
void insertathead(node*&head,int data){
    node*nodetoinsert=new node(data);
    head->prev=nodetoinsert;
    nodetoinsert->next=head;
    head=nodetoinsert;
    
}
void insertattail(node*&tail,int data){
    node*nodetoinsert=new node(data);
    nodetoinsert->prev=tail;
    tail->next=nodetoinsert;
    tail=nodetoinsert;
}
void insertatposition(node*&head,node*&tail,int data,int position){
 node*nodetoinsert=new node(data);

 if(position==1){
    insertathead(head,data);
    return;
 }
  node*temp=head;
  int ct=1;
  while (ct<position-1)
  {
      temp=temp->next;
    ct++;
  
  }
  if(temp->next==NULL){
    insertattail(tail,data);
    return ;
  }
  temp->next->prev=nodetoinsert;
  nodetoinsert->next=temp->next;
  temp->next=nodetoinsert;
  nodetoinsert->prev=temp;
  
  

}

void deletebyposition(node*&head,int position){
    if(position==1){
    node*temp=head;
    temp->next->prev=NULL;  // first deleting the backward link of next node
    head=temp->next;   // shifting the head to the next node using forward link
    temp->next=NULL;  // now making the pointing the forward link to null
    delete temp; // finnaly deleting the temp pointer using destructor
    }
    //delete the remaining
    int ct=1;
    node*curr=head;
    node*prev=NULL;
    while (ct<position)
    {
        ct++;
        prev=curr;
       curr=curr->next;
      
    }
     curr->prev=NULL;
     prev->next=curr->next;
     curr->next=NULL;
     delete curr;
    
}
int main(){
node*n1=new node(34);
node*head=n1;
node*tail=n1;
insertathead(head,51);
insertattail(tail,45);
deletebyposition(head,2);
insertattail(tail,43);
insertatposition(head,tail,98,4);
print(head);

return 0;
}
