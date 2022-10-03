// Reverse a linked list
// 3,4,2,1,5
// reverse- 5,1,2,4,3 

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
    int value=this->data;
    if(this->next!=NULL){
        delete next;
    }
    cout<<"the deleted value is"<<value<<endl;
}
};
void insertathead(node*&head,int data){
node*temp=head;
node*nodetoinsert=new node(data);
nodetoinsert->next=temp;
head=nodetoinsert;

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
   
// reversal using recursion
node*reverse(node*head){
if(head==NULL ||head->next==NULL){
    return head;
}
// we had stored the value of head next to a variable so that it becomes tail
node*new_tail=head->next;
node*last_ka_head_de=reverse(head->next);
head->next=NULL;
new_tail->next=head;
return last_ka_head_de;
}

// reversal using iteration
node* reverselinkedlist(node*head){
node*prev=NULL;
node*curr=head;
node*forward=curr->next;
while (curr!=NULL)
{
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;    
}
head=prev;
 return head;
}


node*middle(node*&head){
    int ct=0;
    node*temp=head;
    while(temp!=NULL){
        ct++;
        temp=temp->next;
    }
    int ct3=ct/2-1;
    node*ans=head;
    while(ct3--)ans=ans->next;
    return ans;
}
void reverse(node*s,node*e){
node*pre=NULL,*curr=s,*nex=curr->next;
while(pre!=e){
    curr->next=pre;
    pre=curr;
    curr=nex;
if(nex!=NULL)
    nex=nex->next;
}
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  node *n1=new node(1);

  node*head=n1;

  insertathead(head,2);
  insertathead(head,4);
  insertathead(head,3);
//   insertathead(head,63);
    print(head);
//     cout<<"Reverse using iteration"<<endl;
// node*newhead=reverselinkedlist(head);
//   print(newhead);

      
// cout<<"Reverse using recursion:"<<endl;
//  node*head3= reverse(head);
//   print(head3);

return 0;
}
