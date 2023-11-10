// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//   int value;
//   struct Node* next;
//   Node(int value){
//     this->value=value;
//     next=NULL;
//   }
// };

// struct LL{
// Node* head;
//  LL(){
//   head=NULL;
//   }
//   void reverse(){
//   Node* curr=head;
//   Node* prev=NULL,*next=NULL;
//   while(curr!=NULL){
//   next=curr->next;
//   curr->next=prev;
//   prev=current;
//   current=next;
//   }
//   head=prev;
//   }
//   void print(){
//   struct Node* temp=head;
//   while(temp!=NULL){
//   cout<<temp->value<<" ";
//   temp=temp->next;
//   }
//   }
//   void push(int value){
//   Node* temp=new Node(value);
//   temp->next=head;
//   head=temp;
//   }
// };
// int main(){
// LL obj;
// obj.push(5);
// obj.push(60);
// obj.push(4);
// obj.push(9);
// cout<<"Entered linked list is: "<<endl;
// obj.print();
// obj.reverse();
// cout<<"Reversed linked list is: "<<endl;
// obj.print();
//   return 0;
// }


// }


#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int data){
      this -> data = data;
      this -> next = NULL;
    }
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; 
}

void push(Node* &head,int data) {
  Node* temp = new Node(data);
  temp -> next = head;
  head = temp;
}
void print(Node* head) {
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<"-> ";
    temp = temp->next;
  }
  cout<<endl;
}
int main () {
  Node* head = new Node(10);
  push(head,11);
  push(head,12);
  push(head,13);
  push(head,14);
  push(head,15);
  cout<<"Original LinkedList: "<<endl;
  print(head);
  head = reverse(head);
  cout<<"Reverse LinkedList: "<<endl;
  print(head);

}