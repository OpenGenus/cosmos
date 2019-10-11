/*
 * 
 * Title:       Stack with array implementation.
 * Author:      Viswalahiri Swamy Hejeebu
 * GitHub:      https://github.com/Viswalahiri
 * LinkedIn:    https://in.linkedin.com/in/viswalahiri
 *  
 */
 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};
struct Node *head=NULL;

void dequeue()
{
	if(head==NULL)
	{
		cout<<"Queue Underflow."<<endl;
		return;
	}
	if(head->next==NULL)
	{
		struct Node *temp=head, *temp2;
		
		if(temp!=NULL)
		{
			temp2=temp;
			temp=temp->next;
		}
	//	temp1=temp;
		head=NULL;
		cout<<"The dequeued value is "<<temp2->data<<endl;
		free(temp2);
		return;	
	}
	else
	{
		struct Node *temp=head, *temp2;
		while(temp->next!=NULL)
		{
			temp2=temp;
			temp=temp->next;
		}
		temp2->next=NULL;
		cout<<"The dequeued value is "<<temp->data<<endl;
		free(temp);
		return;
	}	
}

void enqueue(int value)
{
	struct Node *new_node;
	new_node = (struct Node*)malloc(sizeof(struct Node));
	cout<<"The value "<<value<<" has been pushed."<<endl;
	new_node->data=value;
	new_node->next=head;
	head=new_node;
	
}

//Driver Program
int main()
{
	
	while(1)
	{
	cout<<"1 - enqueue"<<endl;
	cout<<"2 - dequeue"<<endl;
	cout<<"3 - exit"<<endl;
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Push what?"<<endl;
			int to_push;
			cin>>to_push;
			enqueue(to_push);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout<<"The option you have requested isn't present."<<endl;
	}
	
	}
	return 0;
}
