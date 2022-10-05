// insertatnode
// print --> traversal
// deletion


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
class node{
public:
int data;
node*next;
node(int data)
{
    this->data=data;
    this->next=NULL;
}
};

void insertatposition(node*&tail,int element,int data){
    // insert at first position

 if(tail==NULL){
    // EMPTY LINKEED LIST
    node*nodetoinsert=new node(data);
    tail=nodetoinsert;
    nodetoinsert->next=nodetoinsert;
 }
 else{
 // insertatany position
    node*temp=tail;
 while (temp->data!=element)
 {
    temp=temp->next;
 }
 node*nodetoinsert=new node(data);
  nodetoinsert->next=temp->next;
 temp->next=nodetoinsert;
} 
}
void print(node*tail){
    node*temp=tail;
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
     }
     while (tail->next!=temp);
     cout<<endl;
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
return 0;
}
