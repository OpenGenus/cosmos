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
class Stack{
    node*head;
    int top;
    public:
    Stack(){
        top=-1;
        head=NULL;
    }
    void push(int element){
        top++;
        node*new_node=new node(element);
        new_node->next=head;
        head=new_node; 
    }
    void pop(){
        top--;
        if(head!=NULL)
        node*curr=head->next; 

    }
};


int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);



return 0;
}
