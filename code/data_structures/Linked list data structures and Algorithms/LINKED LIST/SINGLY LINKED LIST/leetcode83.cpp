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
    ~node(){
        int val=this->data;
        if(this->next!= NULL){
            delete next;
        }
        cout<<"deleted val"<<val<<" ";
    }
};
void insertathead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
node* deleteduplicate(node*head){
    node*_Dummy=new node(-1);
    _Dummy->next=head;
    node*curr=head;
   node*forward=head->next;
while (forward!=NULL)
{
    if(curr->data==forward->data){
        node*temp=forward;
        forward=forward->next;
        curr->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        curr=curr->next;
        forward=forward->next;
    }
}
return _Dummy->next;


}
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
node*n1=new node(4);
node*head=n1;
insertathead(head,4);
insertathead(head,4);
insertathead(head,3);
insertathead(head,2);
insertathead(head,2);;
insertathead(head,1);
print (head);
node*h1=deleteduplicate(head);
cout<<endl;
print(h1);
return 0;
}
