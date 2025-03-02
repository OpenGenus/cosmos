#include<iostream>
#include<stdio.h>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
int intersectPoint(struct Node* head1, struct Node* head2);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
int main()
{
    int T,i,n1, n2, n3,l,k;
    cout<<"Enter the number of test cases"<<endl;
    cin>>T;
    while(T--)
    {
	cout<<"Enter the  number of nodes before merge point in 1st list,number of nodes before merge point in 2nd list and number of nodes after merge point"	      <<endl;
        cin>>n1>>n2>>n3;
	cout<<"Enter the nodes"<<endl;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
	 cout <<"The intersection point is " << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    int len1 =0,len2=0;
    Node *cur1 = head1;
    Node *cur2 = head2;
    while(cur1 != NULL){
        len1++;
        cur1 = cur1->next;
    }
    while(cur2 != NULL){
        len2++;
        cur2 = cur2->next;
    }
    if(len1 < len2){
        for(int i=0;i<(len2-len1);i++){
            head2 = head2->next;
        }
    }
    if(len1 > len2){
        for(int i=0;i<(len1-len2);i++){
            head1 = head1->next;
        }
    }
    while(head1 != NULL && head2 != NULL){
        if(head1  == head2){
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;   
}
