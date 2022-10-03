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

void insertattail(node*&tail,int data){
     node*nodetoinsert=new node(data);
     tail->next=nodetoinsert;
     tail=nodetoinsert;
     
}
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node* mergeTwoLists(node* list1, node* list2) {
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  node*n1=new node(2);
  node*head=n1;
  node*tail=n1;
  insertattail(tail,3);
  insertattail(tail,4);
  print(head);



return 0;
}
