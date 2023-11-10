#include<bits/stdc++.h>
using namespace std;
struct Node{
  int value;
  struct Node* next;
  Node(int value){
    this->value=value;
    next=NULL;
  }
};

struct LL{
Node* head;
 LL(){
  head=NULL;
  }
  void reverse(){
  Node* curr=head;
  Node* prev=NULL,*next=NULL;
  while(curr!=NULL){
  next=curr->next;
  curr->next=prev;
  prev=current;
  current=next;
  }
  head=prev;
  }
  void print(){
  struct Node* temp=head;
  while(temp!=NULL){
  cout<<temp->value<<" ";
  temp=temp->next;
  }
  }
  void push(int value){
  Node* temp=new Node(value);
  temp->next=head;
  head=temp;
  }
};
int main(){
LL obj;
obj.push(5);
obj.push(60);
obj.push(4);
obj.push(9);
cout<<"Entered linked list is: "<<endl;
obj.print();
obj.reverse();
cout<<"Reversed linked list is: "<<endl;
obj.print();
  return 0;
}


}
