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
    cout<<"the delete value is"<<" "<<val<<endl;
  }
};
void deletenode(node*&tail,int element){
  // for empty linked list
  if(tail==NULL){
    return;
  }

  else{
node*prev=tail;
node*curr=prev->next;
while (curr->data!=element)
{
  prev=curr;
  curr=curr->next;
}
prev->next=curr->next;
if(curr==prev){
  tail=prev;
}
if(tail==curr){
  tail=prev;
}
curr->next=NULL;
delete curr;
  }
  
}

void insertatposition(node*&tail,int element,int data){
  // when there is empty list
  
  if(tail==NULL){
    node*nodetoinsert=new node(data);
    tail=nodetoinsert;
    nodetoinsert->next=nodetoinsert;
  }
  else{
    // for remaining position
    node *curr=tail;
    while (curr->data!=element)
    {
      curr=curr->next;
    }
    node*temp=new node(data);
  temp->next=curr->next;
  curr->next=temp;
    
  }
}
void print(node*&tail){
  node*temp=tail;
  if(tail==NULL){
    cout<<"Empty list";
    return ;
  }
  do
  {
    cout<<tail->data<<" ";
    tail=tail->next;
  } while (tail!=temp);
  cout<<endl;
}
bool circularcheck(node*tail){
    if(tail==NULL){
        return true;
    }
    node*temp=tail;
    while (temp->next!=tail && temp!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next=tail){
        return true;
    }
    return false;
    
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // since there is no element at begening
node*tail=NULL;
insertatposition(tail,4,5);
print(tail);
insertatposition(tail,5,6);
print(tail);
insertatposition(tail,6,7);
print(tail);
insertatposition(tail,7,8);
print(tail);
insertatposition(tail,5,10);
print(tail);
bool a=circularcheck(tail);
cout<<a<<" ";

return 0;
}
