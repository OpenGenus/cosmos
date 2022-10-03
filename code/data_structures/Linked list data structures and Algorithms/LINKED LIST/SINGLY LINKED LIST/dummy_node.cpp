#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
        }
        cout << "The deleted value is:" << value << " " << endl;
    }
};
void insertathead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertatposition(node *&head, int data, int position)
{
    node *nodetoinsert = new node(data);
    if (position == 1)
    {
        insertathead(head, data);
        return;
    }

    node *temp = head;
    int ct = 1;
    while (ct <= position)
    {
        temp = temp->next;
        ct++;
    }
    if (temp->next == NULL)
    {
    }
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void deletenode(node *&head, int position)
{
    if (position == 1)
    {
        node *temp = head;
        temp->next = NULL;
        delete (temp);
    }
    else
    {
        int ct = 1;
        node *prev = head;
        node *curr = head;
        while (ct < position)
        {
            prev = curr;
            curr = curr->next;
            ct++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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
int length(node*&head){
    node*temp=head;
    int ct=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        ct++;
    }
    return ct;
    
}
node *reverse(node *&head, int k)
{
if(head->next==NULL || head==NULL|| k==1)
return head;


    node *_Dummy = new node(-1);
      _Dummy->next = head;
    node *pre = _Dummy;
    node *curr = _Dummy;
    node *nex = _Dummy;

  
    int len=length(head);
    
    while (len>=k)
    {
        curr = pre->next;
        nex = curr->next;
      for (int i = 0; i < k-1; i++)
      {
          curr->next=nex->next;
          nex->next=pre->next;
          pre->next=nex;
          nex=curr->next;  
     
      }
      pre=curr;
      len=len-k;
      
    }

    return _Dummy->next;
}
node*deletenode_back(node*head,int n){
    if(head==NULL)return NULL;
    //for the remaining nodes
    int a=length(head)-n;
    int ct=0;
    node*dummy=new node(-1);
    dummy->next=NULL;
    node*curr=dummy;
    node*pre=NULL;
    while(ct<a){
        pre=curr;
        curr=curr->next;
        ct++;

    }
    node*node_to_delete=curr;
    if(curr!=NULL)
        curr=curr->next;
        pre->next=curr;
        delete(node_to_delete);
    return dummy->next;

}
int main()
{
    node *n1 = new node(6);
    node *head = n1;
    insertathead(head, 5);
    insertathead(head, 4);
    insertathead(head, 3);
    insertathead(head, 2);
    insertathead(head, 1);
  print(head);
 node*h1=deletenode_back(head,2);
 print(h1);
    /* func(head,k){
        // check if k<=length then do else attach with the next head



    }*/
    return 0;
}
