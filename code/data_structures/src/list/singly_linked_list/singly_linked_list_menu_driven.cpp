#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    struct node* link;
    node(int d):data(d),link(NULL){}
};

void display(node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->link;
    }
    cout<<"\n";
}

void atTail(node* &tail,int d){
    node *temp = new node(d);
    tail->link = temp;
    tail = temp;
}

void atHead(node* &head,int d){
    node *temp = new node(d);
    temp->link = head;
    head = temp;
    display(head);
}

void atPos(node* cur,int d,int pos){
    node *temp = new node(d);
    pos--;
    while(pos-->1) cur = cur->link;
    temp->link = cur->link;
    cur->link = temp;
}

void delHead(node* &head){
    node* temp = head->link;
    head->link= NULL;
    head = temp;
    display(head);
}

void delTail(node* cur,node* &tail){
    while (cur->link->link!=NULL) cur=cur->link;
    tail = cur;
    tail->link=NULL;
}

void delPos(node* cur,int pos){
    pos--;
    while(pos-->1) cur = cur->link;
    cur->link = cur->link->link;
}

int searching(node* cur,int d){
    int p = 0;
    while(cur->data!=d && cur->link!=NULL){
        cur=cur->link;
        p++;
    }
    if(cur->data==d) return p+1;
    else return p;
}

int main(){
    cout<<"\nHello there! Welcome to linked list...\n"
        <<"Enter the no. of elements: ";
    int n,d,p,x;
    cin>>n;
    cin>>d;
    node *head = new node(d);
    node *tail = head;
    x=n;
    while(n-->1)
    {
        cin>>d;
        atTail(tail,d);
    }
    while (1)
    {
        cout<<"----------------------------------------------\n"
            <<"1. Add elements\n"
            <<"2. Delete elements\n"
            <<"3. Searching elements\n"
            <<"4. Display Elements\n"
            <<"5. Exit\n"
            <<"Enter your choice: ";
        int choice;cin>>choice;
        switch (choice)
        {
        case 1:
            while(1){
                cout<<"----------------------------------------------\n"
                    <<"\t1. At head\n"
                    <<"\t2. At tail\n"
                    <<"\t3. At Position\n"
                    <<"\t4. Back\n"
                    <<"\tEnter your choice: ";
                int c;cin>>c;
                if(c==4) break;
                if(c==1||c==2||c==3||c==4){
                    cout<<"\tEnter the value: ";
                    cin>>d;
                }
                if(c==1) atHead(head,d);
                else if(c==2){
                    atTail(tail,d);
                    display(head);
                }
                else if(c==3){
                    cout<<"\tEnter the position: ";
                    cin>>p;
                    if(p==0||p==1) atHead(head,d);
                    else atPos(head,d,p);
                    display(head);
                }
                else cout<<"Invalid choice...\n";
            }
            break;
        
        case 2:
            while (1)
            {
                cout<<"----------------------------------------------\n"
                    <<"\t1. At head\n"
                    <<"\t2. At tail\n"
                    <<"\t3. At Position\n"
                    <<"\t4. Back\n"
                    <<"\tEnter your choice: ";
                int c;cin>>c;
                if(c==4) break;
                if(c==1) delHead(head);
                else if(c==2){
                    delTail(head,tail);
                    display(head);
                }
                else if(c==3){
                    cout<<"\tEnter the position: ";
                    cin>>p;
                    if(p==0||p==1) delHead(head);
                    else delPos(head,p);
                    display(head);
                }
                else cout<<"Invalid choice...\n";
            }
            break;
        case 3:
            cout<<"Enter the element to search: ";
            cin>>d;
            x=searching(head,d);
            if(x) cout<<"Elemenet found at position "<<x<<"\n";
            else cout<<"Element not found...\n";
            break;
        case 4:
            display(head);
            break;
        case 5:
            return 0;
        default:
            cout<<"Invalid input...\n";
            break;
        }
    }
    return 0;
}
