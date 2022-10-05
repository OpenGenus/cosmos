#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node*next;
node(int data){
    this->data=data;
    this->next=NULL;
}
~node(){
    int value=this->data;
    if(this->next!=NULL){
      delete next;
    }
   // cout<<"The deleted value is:"<<value<<" "<<endl;
}
};
void insertathead(node*&head,int data){
    node*temp=new node(data);
    temp->next=head;
    head=temp;
}

void insertatposition(node*&head,int data,int position){
    node*nodetoinsert=new node(data);
    if(position==1){
        insertathead(head,data);
        return;
    }
    
    node*temp=head;
        int ct=1;
        while (ct<=position)
        {
            temp=temp->next;
            ct++;
        }
        if(temp->next==NULL){
            
        }
        nodetoinsert->next=temp->next;
        temp->next=nodetoinsert;
        
    }

int length(node*head){
    int ct=1;
   node*temp=head;
   while(temp!=NULL){
    temp=temp->next;
    ct++;

   }return ct;
}
void delete_back(node*head,int n){
    // let suppose for n=3
if(head==NULL)return ;

node*_Dummy=new node(-1);
_Dummy->next=head;
node*curr=_Dummy;
node*prev=NULL;
int ct=0;
int l=length(head);
int a=l-n;
  if(l==n){
        
        
    }
        while(ct<a){
           prev=curr;
           curr=curr->next;
           ct++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

}
void deletenode(node*&head,int position){

    if(position==1){
        node*temp=head;
        temp->next=NULL;
        delete (temp);
    }
    else{
        int ct=1;
        node*prev=head;
        node*curr=head;
        while(ct<position){
           prev=curr;
           curr=curr->next;
           ct++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(node*&head){
    node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}


int main(){
node*n1=new node(5);
node*head=n1;
insertathead(head,4);
insertathead(head,3);
insertathead(head,2);
insertathead(head,1);
insertathead(head,0);
// insertatposition(head,45,2);
// deletenode(head,2);
print(head);
cout<<endl;
delete_back(head,6);
print(head);
return 0;
}
