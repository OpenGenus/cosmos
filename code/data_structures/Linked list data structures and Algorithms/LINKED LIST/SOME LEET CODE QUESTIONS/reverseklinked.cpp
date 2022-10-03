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

// node*reverseknodes(node*head,int k){
// // base case

// if(head==NULL || head->next==NULL){
//     return NULL;
// }
// node*curr=head;
// node*prev=NULL;
// node*forward=curr->next;
// int ct=0;
// while (ct<k && curr!=NULL  )
// {
//     forward=curr->next;
//     curr->next=prev;
//     prev=curr;
//     curr=forward;
//     ct++;
// }
// // step 2 here prev is the new head after reversing the first k groups,
// // so we have to point the new head to the remaining part 
// if(k<=length(forward))
// head->next=reverseknodes(forward,k);
// else
// head->next=forward;
// return prev;
// }

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

  node*ans=
return 0;
}

