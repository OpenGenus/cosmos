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
void insertattail(node*&tail,int data){
    node*nodetoinsert=new node(data);
    tail->next=nodetoinsert;
    tail=nodetoinsert;
}
void insertatposition(node*head,node*&tail,int data,int position){
    // if the list is empty
    if(head==NULL){
        insertathead(head,data);
        return;
    }
    int ct=1;
    node*temp=head;
    while (ct<=position-1)
    {
        temp=temp->next;
        ct++;
    }
    if(temp->next=NULL){
        insertattail(tail,data);
        return;
    }
   node*nodetoinsert=new node(data);
   nodetoinsert->next=temp->next;
   temp->next=nodetoinsert;

    
}
int detectcycle(node*&head){
    map<node*,bool>m;
  node*temp=head;
  while (temp!=NULL)
  {
    if(m[temp]==true)
    return 1;
    // if it is circular
      m[temp]=true;
      temp=temp->next;
     
  }
   return 0;
}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 node *n1=new node(5);

  node*head=n1;
  node*tail=n1;

  insertathead(head,4);
  insertathead(head,3);
  insertathead(head,2);
  insertathead(head,1);
  insertattail(tail,6);
   print(head);
  tail->next=head->next->next;
  cout<< detectcycle(head)<<endl;
  
  
return 0;
}

