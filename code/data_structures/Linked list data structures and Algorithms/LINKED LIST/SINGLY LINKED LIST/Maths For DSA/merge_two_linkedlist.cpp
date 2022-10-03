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
void print(node*&head){
    node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
void insertathead(node*head,int data){
    node*new_node=new node(data);
    new_node->next=head;
    head=new_node;
    return ;
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
node*n1=new node(1);
node*head=n1;
insertathead(head,34);
print(head);
return 0;
}
