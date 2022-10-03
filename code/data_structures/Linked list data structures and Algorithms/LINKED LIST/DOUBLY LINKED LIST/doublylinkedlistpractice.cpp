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
};
void insertathead(node*&head,int data)
{
    node*nodetoinsert=new node(data);
   
    head->prev=nodetoinsert;
    nodetoinsert->next=head;
    head=nodetoinsert;

}
void insertattail(node*tail,int data){
node*nodetoinsert=new node(data);

nodetoinsert->prev=tail;
tail->next=nodetoinsert;
tail=nodetoinsert;

}
void insertatposition(node*&head,node*&tail,int data,int position){
  
    if(position==1){
     insertathead(head,data);
     return;
    }
    
    
   int ct=1;
   node*temp=head;
  
 
     node*nodetoinsert=new node(data);
   while (ct<position-1)
   {
    temp=temp->next;
    ct++;
   }
   if(temp->next==NULL){
   insertattail(tail,data);
   return ;
   }
//    nodetoinsert->next=temp->next;
//   temp->next->prev=nodetoinsert;
//   nodetoinsert->prev=temp;
//    temp->next=nodetoinsert;
temp->next->prev=nodetoinsert;
nodetoinsert->next=temp->next;
temp->next=nodetoinsert;
nodetoinsert->prev=temp;
   
    
}
void printnode(node*&head){
node*temp=head;

while (temp!=NULL)
{
    cout<<temp->data<<" ";
      temp->prev=temp;
        head->prev=temp;
        temp=temp->next;
}

}




int main(){
node*n1=new node(3);
// cout<<n1->data<<endl;
node *head=n1;
node *tail=n1;
insertathead(head,43);
insertattail(tail,40);
insertatposition(head,tail,20,3);
printnode(head);
return 0;
}
