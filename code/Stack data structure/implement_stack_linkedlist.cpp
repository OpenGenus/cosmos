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
this->next=next;
}
};
class Stack{
    int size;
    node*head;
    public:
   // constructor to define the stack for initiallisig the memeory
    Stack(){
     head=NULL;
     size=0;
    }
    int get_size(){
        if(head==NULL){cout<<"Stack is empty"<<" "<<endl;
        return -1;
        }
        return size;
    }
    void push(int element){
     if(get_size()==size){
        cout<<"Stack ius full "<<endl;
        return;
     }
     node*temp=new node(element);
    temp->next=head;
    cout<<"Element pushed -->"<<temp->data<<" "<<endl;
    head=temp;
    size++;

    }
    void pop(){
      // first cv
      if(head==NULL){
        cout<<"Empty stack"<<" ";
        return ;
      }
      node*node_to_delete=head;
     int val=node_to_delete->data;
      head=head->next;
      delete node_to_delete;
      size--;
      cout<<"Popped value is"<<val<<endl;
    }
int is_empty(){
if(head==NULL)return 1;
else
return 0;
}

};
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
Stack s1;
s1.is_empty();
s1.push(3);
s1.pop();
if(s1.is_empty())cout<< true;
else
cout<< false;
return 0;
}
