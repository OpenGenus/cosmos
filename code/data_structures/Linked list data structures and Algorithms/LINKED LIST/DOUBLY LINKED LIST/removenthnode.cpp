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
node*last_ka_head_de=reverse(head->next);
head->next->next=head; // second node ko ulta krke first me point kro
head->next=NULL; // ab first ko ulta kr do aur null ko point kr do
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
void deletenode(node*&head,int position){
    //empty list
    if(head==NULL){return;}
    // single node
    if(position==1){
        node*temp=head;
        delete temp;
    }
    int ct=1;
    node*prev=head;
    node*curr=head;
    while (ct<position)
    {
        prev=curr;
        curr=curr->next;
        ct++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;

}

int  positionfromfirst(node*&head,int positionfromlast){

    int ct=0;
    
    while (head!=NULL)
    {
        ct++;
        head=head->next;
    }
    int lengthformfirst=ct-positionfromlast+1;
    deletenode(head,lengthformfirst);
return lengthformfirst;
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  node *n1=new node(34);

  node*head=n1;

  insertathead(head,43);
  insertathead(head,56);
  insertathead(head,57);
  insertathead(head,63);
    print(head);


deletenode(head,positionfromfirst(head,2));
print(head);
return 0;
}
