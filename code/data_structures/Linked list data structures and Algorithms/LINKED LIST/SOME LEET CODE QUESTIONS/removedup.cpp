#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
class node{
    public:
    int data;
    node*next;
node(int data){
    this->data=data;
    this->next=NULL;
}
~node(){
    int val=this->data;
    if(this->next!=NULL){
        delete next;
    }
    cout<<"Deleted val is :"<<val<<" ";
}
};

void insertattail(node*&tail,int data){
    node*nodetoinsert=new node(data);
    if(tail==NULL){
        return;
    }
    tail->next=nodetoinsert;
    tail=nodetoinsert;
}
void print(node*&head){
    if(head==NULL){
        return;
    }
    node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } 
    cout<<endl;    
}
void remove_duplicates(node*&head){
if(head==NULL )return;

node*curr=head;
while (curr!=NULL)
{
     
    if(curr->data==curr->next->data && curr->next!=NULL){
      node*node_to_delete=curr->next;
      node*temp=curr->next;
      delete (node_to_delete);
      curr->next=temp;
    }
    else{
        curr=curr->next;
    }
}



}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
node *n1=new node(3);
node*tail=n1;
node*head=n1;
insertattail(tail,3);
insertattail(tail,4);
insertattail(tail,4);
insertattail(tail,5);
insertattail(tail,6);
insertattail(tail,7);
insertattail(tail,7);
print(head);
return 0;
}
