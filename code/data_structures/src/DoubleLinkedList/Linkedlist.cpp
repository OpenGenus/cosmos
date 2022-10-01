#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

class node{  //node of linked list
     public:
     int data;
     node* next;

     node(){
          data=0;
          next=NULL;
     }
     node(int data){
          this->data =data;
          this->next =NULL;
     }
};
class linked_list{
     node* head;

     public:
     linked_list(){
          head=NULL;
     }
    void insertion(int);
    void insertionlast(int);
    void insertionmid(int);
    void deletion();
    void deletionlast();
    void reverse();
    void print();
};
//add at first
void linked_list::insertion(int data){
     node* newnode =new node(data);
     if(head==NULL){
          head=newnode;
          return;
     }
     newnode->next=head;
     head=newnode;
}
//add at last
void linked_list::insertionlast(int data){
     node* newnode=new node(data);
     if(head==NULL){
          head=newnode; 
          return;
     }
     node* currnode=head;
     while(currnode->next!=NULL){
          currnode=currnode->next;
     }
     currnode->next = newnode;
}
//insert in middle
void linked_list::insertionmid(int data){
     node* newnode=new node(data);
     if(head==NULL){
          head=newnode;
          return;
     }
     else{
     node* currnode=head;
     int size=0;
     while(currnode->next!=NULL){
          size++;
          currnode=currnode->next;
     }
     int count=((size%2==0))?(size/2):(size+1)/2;
     currnode=head;
     while (count-- > 1)
          currnode = currnode->next;  //currnode points to the node after which the new node is to be inserted
     newnode->next = currnode->next;
     currnode->next = newnode;
     }
}
//deletion
//deletion at first
void linked_list::deletion(){
     if(head==NULL){
          cout<<"The list is empty";
          return;
     }
     head=head->next;
}
//delete last
void linked_list::deletionlast(){
     if(head==NULL){
          cout<<"The list is empty";
          return;
     }
     if(head->next==NULL){
          head=NULL;
          return;
     }
     node* secondlast= head;
     node* lastnode= head->next;
     while(lastnode->next != NULL){
          lastnode=lastnode->next;
          secondlast=secondlast->next;
     }
     secondlast->next=NULL;
}
//reversing a linked list
void linked_list::reverse(){
   
}
//print
void linked_list::print(){
     node* currnode = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    while (currnode!= NULL) {
        cout << currnode->data << " ";
        currnode = currnode->next;
    }
    cout<<"NULL";
}
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     linked_list list;

     list.insertion(1);
     list.insertion(5);
     list.insertion(11);

     list.insertionlast(6);
     list.insertionlast(9);
     list.insertionlast(13);
     cout<<"elements inserted are: ";

     list.print();
     cout<<endl;

     list.deletion();

     cout<<"Elements left in linked list are: ";

     list.print();
     cout<<endl;
     list.deletionlast();

     cout<<"Elements left in linked list are: ";

     list.print();
     cout<<endl;

     list.insertionmid(7);
     list.insertionmid(10);

     cout<<"elements inserted are: ";

     list.print();
     cout<<endl;

     list.reverse();
     cout<<"REVERSED LINKED LIST"<<endl;
     list.print();

     return 0;
}
