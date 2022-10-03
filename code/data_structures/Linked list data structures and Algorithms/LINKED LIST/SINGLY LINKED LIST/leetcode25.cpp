#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
class ListNode{
    public:
    int data;
    ListNode*next;
    ListNode(int data){
        this->data=data;
        this->next=next;
    }
};
void insertathead(ListNode *&head, int data)
{
    ListNode *temp = new ListNode(data);
    temp->next = head;
    head = temp;
}
void print(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int length(ListNode*head){
int ct=0;
ListNode*temp=head;
while (temp!=NULL)
{
    temp=temp->next;
    ct++;
}
return ct;
}
ListNode*reverse(ListNode*head,int k){
    if(head==NULL|| k==1){
        return head;
    }
  
    ListNode*dummy=new ListNode(-1);
    ListNode*pre=dummy;
    ListNode*curr=dummy;
    ListNode*nex=dummy;
    int len=length(head);
    while (len>=k)
    {
        curr=pre->next;
        nex=curr->next;
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
    
    return dummy->next;
   

}


int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
ListNode *n1 = new ListNode(6);
    ListNode *head = n1;
    insertathead(head, 5);
    insertathead(head, 4);
    insertathead(head, 3);
    insertathead(head, 2);
    insertathead(head, 1);
  
 ListNode*h1=reverse(head,2);
 print(h1);
return 0;
}
