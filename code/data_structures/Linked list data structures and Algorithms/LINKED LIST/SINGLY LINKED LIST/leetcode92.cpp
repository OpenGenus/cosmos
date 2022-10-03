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
void insertathead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
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
node*reverse_start_end(node*head){
   
  node*prev=NULL;
node*nex=head->next;
node*curr=head;
while (curr!=NULL)
{
    curr->next=prev;
    prev=curr;
    curr=nex;
    nex=nex->next;
}
return prev;
    
    
}
 node* reverseBetween(node* head, int left, int right) {
// find start
node*curr=head;
node*curr_prev=NULL;
int ct=1;
while (ct!=left)
{
    curr_prev=curr;
    curr=curr->next;
    ct++;
}
node*start=curr;

while (ct!=right)
{
    curr=curr->next;
    ct++;
}
node*rest=curr->next;

    }
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
node*n1=new node(34);
node*head=n1;

insertathead(head,33);
insertathead(head,32);
insertathead(head,31);
insertathead(head,30);
insertathead(head,29);
insertathead(head,28);
print(head);
node*h2=reverseBetween(head,2,5);
print(h2);
return 0;
}
