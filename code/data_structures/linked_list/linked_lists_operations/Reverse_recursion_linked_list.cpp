#include<iostream>
#include<stack>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

class node{
public:
    int data;
    node* next;

public:
    node(int d){
        data=d;
        next=NULL;
    }
};

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
}

void insertAtHead(node*&head,int d){
    node* n=new node(d);
    n->next=head;
    head=n;
}

void insertInMiddle(node*&head,int d,int p){
    if(p==0){
        insertAtHead(head,d);
    }
    else{
        //assuming p<=length of LL
        int jump=1;
        node*temp=head;
        while(jump<=p-1){
            jump++;
            temp=temp->next;
        }
        node*n=new node(d);
        n->next=temp->next;
        temp->next=n;
    }
}

void takeInput(node*&head){
    int d;
    cin>>d;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
}

///overloading to print LL
ostream& operator<<(ostream&os, node*head){
    print(head);
    cout<<endl;
    return os;
}
istream& operator>>(istream&is, node*&head){
    takeInput(head);
    return is;
}


///optimized recursive reverse
node*recReverse2(node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*newHead=recReverse2(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

int main(){
    node*head=NULL;
    cin>>head;
    cout<<head;
    head=recReverse2(head);
    cout<<"Reversed linked list: "<<endl;
    cout<<head;



    return 0;
}
