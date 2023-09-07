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
#define SIZE 5
using namespace std;
int front =-1;
int rear =-1;
int queues[SIZE];

void dequeue()
{
	if(rear==front)
	{
		cout<<"Queue Underflow."<<endl;
		rear=front=-1;
		return;
	}
	if(rear > front)
	{
		front+=1;
		cout<<"The dequeued value is "<<queues[front]<<endl;
		if(rear == front)
		{
			rear=front=-1;
		}
		return;	
	}
	return;
}	


void enqueue(int value)
{
	if(rear==SIZE-1)
	{
		cout<<"The queue is overflowing."<<endl;
	}
	else
	{
	rear+=1;
	queues[rear]=value;
	cout<<"The value "<<value<<" has been pushed."<<endl;
	}
	return;
	
}

void display()
{
	int i=front;
	cout<<"Start ";
	while(i<rear)
	{
		cout<<queues[i+1]<<" ";
		i+=1;
	}
	cout<<" End"<<endl;
	return;
}

//Driver Program

int main()
{
	
	while(1)
	{
	cout<<"1 - enqueue"<<endl;
	cout<<"2 - dequeue"<<endl;
	cout<<"3 - display"<<endl;
	cout<<"4 - exit"<<endl;
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
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout<<"The option you have requested isn't present."<<endl;
	}
	
	}
	return 0;
}
