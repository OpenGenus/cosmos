/* This code detects and removes cycle in a linked list,
	it also transforms circular lists into linear lists.

	Data Entry: Beginning
	Cycle Placement: Nth Position
	Cycle Detection: Nth Position
	Cycle Removal: Nth Position

	By: Sarthi Chugh (user: sarthi92)
		BITS, Pilani
*/
#ifndef _IOSTREAM_H
#include<iostream>
#endif
using namespace std;
struct Node
{
    int data;
    Node* next;
}*head;

int linked_list_operations(int ch,int x)
{
    Node *temp1,*temp2;
    Node *n;
    switch(ch)
    {
    case 1://Node Insertion with data=x at beginning of the List
        n=new Node;
        n->data=x;
        n->next=head;
        head=n;
        break;
    case 2://Cycle Placement at position=x
        if(head!=NULL)
        {
        for(temp1=head;temp1->next!=NULL;temp1=temp1->next);
        for(temp2=head;x>1;x--,temp2=temp2->next);
        temp1->next=temp2;
        }
        break;
    case 3://Cycle Check
        x=0;
        temp1=temp2=head;
        while(temp2!=NULL&&temp2->next!=NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next->next;
            if(temp2->next->next==head)
            {temp2->next->next=NULL;break;}//Transforms Circular List to Linear List
            if(temp2->next==head)
            {temp2->next=NULL;break;}//Transforms Circular List to Linear List
            if(temp1==temp2){x=1;break;}//Cycle Detection
        }
        if(x==1)
        {
            for(temp1=head;temp1->next!=temp2->next;temp1=temp1->next,temp2=temp2->next);
            temp2->next=NULL;//Cycle Removal
        }
        break;
    default:break;
    }
    return 0;
}
