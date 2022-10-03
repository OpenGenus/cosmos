#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
class node {
    public:
    int data;
    node*next;
    node*prev;
    node(int data){
        this->data=data;
        this->prev=NULL;
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
    void  insertattail(node*&tail,int data){
       node*nodetoinsert=new node(data);
       tail->next=nodetoinsert;
       nodetoinsert->prev=tail;
       tail=nodetoinsert;

    }
    void insertathead(node*&head,int data){
node*nodetoinsert=new node(data);
head->prev=nodetoinsert;
nodetoinsert->next=head;
head=nodetoinsert;
}
node* reverse(node*head){

    if (head->next==NULL || head==NULL)
    {
        return head;
    }

    node*bring=reverse(head->next);

    head->next->next=head; // second node ko ulta krke first me point kro
head->next=NULL; // ab first ko ulta kr do aur null ko point kr do
return bring;
}
    void insertatpositon(node*&head,node*&tail,int data,int position){
        // for firstpositon
        if( position==1){
            insertathead(head,data);
            return;
        }


        node*temp=head;
        int ct=1;
        while (ct<position-1)
        {
            
            temp=temp->next;
            ct++;
        }
        if(temp->next==NULL){
            insertattail(tail,data);
            return;
        }
        node*nodetoinsert=new node(data);
         nodetoinsert->next->prev=temp;
        temp->next=nodetoinsert;
         temp->next=nodetoinsert;
         nodetoinsert->prev=temp;
    }


int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
node*n1=new node(34);
node*head=n1;
node*tail=n1;
insertattail(tail,45);
insertathead(head,64);
 insertatpositon(head,tail,35,4);
print(head);
node*head3=reverse(head);
print(head3);
return 0;
}
