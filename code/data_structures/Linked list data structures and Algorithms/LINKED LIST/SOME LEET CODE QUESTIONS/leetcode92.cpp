// Love Babbar Reverse K linked List .
// leet code-25
// Microsoft Interview 



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
};
// reversal using iteration
node* reverselinkedlist(node*head,node*end){
node*prev=NULL;
node*curr=head;
node*forward=curr->next;
while (curr!=NULL && head->next!=end)
{
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;    
}
head=prev;
 return head;
}
int length(node*head){
    int ct=0;
    node*temp=head;
    while (temp!=NULL)
    {
        temp=temp->next;
        ct++;
    }
  cout<<ct<<endl;
    return ct;
    
}

node*reverseonlyknodes(node*head,int s,int e){
// first find the positon s and e
node*start=head;
node*startprev=NULL;
node*end=head;
node*endnext=NULL;
int diff=e-s+1;
int ct=0;
while (ct<diff)
{
    endnext=end->next;
    end=end->next;
    ct++;
}
//now  the end is at right position
int cnt=1;
while (cnt<s)
{
    startprev=start;
    start=start->next;
    cnt++;
}
//now the start is also at right position
node*reversedparthead=reverselinkedlist(start,end);
startprev->next=reversedparthead;
reversedparthead->next=end->next;


return reversedparthead;
}

void print(node*&head){
    node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
 
    }
    cout<<endl;
}
void insertathead(node*&head,int data){
    node*nodetoinsert=new node(data);
    nodetoinsert->next=head;
    head=nodetoinsert;
}

int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 node *n1=new node(5);

  node*head=n1;

  insertathead(head,4);
  insertathead(head,3);
  insertathead(head,2);
  insertathead(head,1);
    print(head);
  node*h3=reverseonlyknodes(head,2,4);
  print(h3);
  
return 0;
}

