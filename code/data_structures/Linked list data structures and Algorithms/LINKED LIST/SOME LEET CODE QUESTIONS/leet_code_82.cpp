// Given the head of a sorted linked list, 
// delete all nodes that have duplicate numbers, 
// leaving only distinct numbers from the original list. 
// Return the linked list sorted as well.
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
        if(this->next!=NULL)
        delete next;
        cout<<"Deleted val is:"<<val<<" ";
    }
};
void insertattail(node*&tail,int data){
    if(tail==NULL)
    return ;
    node*nodetoinsert=new node(data);
    tail->next=nodetoinsert;
    tail=nodetoinsert;
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
void deletenode(node*&head,int position){
 
   // deleting start node
   if(position==1){
    node*temp=head;
    head=head->next;
    temp->next=NULL;
    delete(temp);

   }
   else{
   //deleting middle and end node
     node*curr=head;
  node*prev=NULL;
   int ct=1;
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
    
}
node* repeated_till(node*&start){
  node*temp
}
int get_position(node*&head){
    if(head==NULL || head->next==NULL)return -1;
    int ct=1;
    node*temp=head;
    while (temp->data!=temp->next->data)
    {
        ct++;
        temp=temp->next;
    }
    return ct;

}
node* remove_duplicates_2(node*&head){
if(head==NULL || head->next==NULL)return head;
node*_Dummy=new node(-1);
_Dummy->next=head;
node*curr=head;

// find the position of first repeting element
// count upto where the number is repeating
// delete it and repeat the process
return _Dummy->next;


}

int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
node*n1=new node(1);
node*head=n1;
node*tail=n1;
insertattail(tail,2);
insertattail(tail,2);
insertattail(tail,3);
insertattail(tail,3);
insertattail(tail,4);
print(head);
cout<<endl;
// node*h3=remove_duplicates_2(head);
// print(head);
cout<<get_position(head);
return 0;
}
