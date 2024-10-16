//Write a SortedMerge function that takes two lists, each of which is sorted in increasing order, and merges the two together into one list which is in increasing order

#include <bits/stdc++.h>
#define mod 1000000007
#define lli long long int
using namespace std;

class node{
      public:
      int data;
      node* next;

      node(int x){
          data=x;
          next=NULL;

      }
};

void insertATHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void InsertAtTail(node* &head,int val){
    node* n=new node(val);
     node* temp=head;
    if(temp==NULL){
      head=n;
      return;
    }
   
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* mergerecur(node* &head1,node* &head2){
    node* result;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<head2->data){
        result=head1;
        result->next=mergerecur(head1->next,head2);
    }
    else{
        result=head2;
          result->next=mergerecur(head1,head2->next);
    }
    return result;
}
node* merge(node* &head1,node*&head2){
     node* p1=head1;
     node* p2=head2;
     node* dummynode=new node(-1);
     node* p3=dummynode;
     while(p1!=NULL && p2!=NULL){
         if(p1->data<p2->data){
             p3->next=p1;
             p1=p1->next;
         }
          else{
             p3->next=p2;
             p2=p2->next;
         }
         p3=p3->next;
         
     }
        while(p1!=NULL){
             p3->next=p1;
             p1=p1->next;
              p3=p3->next;
         }
         while(p2!=NULL){
             p3->next=p2;
             p2=p2->next;
              p3=p3->next;
         }
         return dummynode;
}


int main(){
    node* head1=NULL;
    node* head2=NULL;
    InsertAtTail(head1,1);
    InsertAtTail(head1,4);
   InsertAtTail(head1,5);
   InsertAtTail(head1,7);
 
   InsertAtTail(head2,3);
    InsertAtTail(head2,4);
      InsertAtTail(head2,6);
     display(head1);
      display(head2);
      node* newhead=mergerecur(head1,head2);
      display(newhead);
return 0;
}
