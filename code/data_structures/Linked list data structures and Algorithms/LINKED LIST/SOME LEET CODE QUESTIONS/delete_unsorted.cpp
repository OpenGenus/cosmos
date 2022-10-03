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
int count_till_rep(node*head){
    int ans=0;
    node*curr=head;
    while(curr->data!=curr->next->data){
       ans++;
       curr=curr->next;
    }
    return ans;
}
int lenght(node*head){
    node*temp=head;
    int ct=0;
    while (temp!=NULL)
    {
        ct++;
        temp=temp->next;
    }
    return ct;
    
}
node*delete_unsorted(node*head){
    if(head==NULL)return head;
    node*curr=head;
    node*ans=head;
    node*pre=head;
    unordered_map<int,int>m;
    node*temp=head;
    // making the frequency array
    while (temp!=NULL)
    {
        m[temp->data]++;
        temp=temp->next;
    }
    
    
}

int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
node *n1=new node(5);
node*tail=n1;
node*head=n1;
insertattail(tail,2);
insertattail(tail,2);
insertattail(tail,4);

print(head);
cout<<endl;
node*h3=delete_unsorted(head);
print(h3);

return 0;
}
