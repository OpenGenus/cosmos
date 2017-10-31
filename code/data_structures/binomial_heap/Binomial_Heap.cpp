#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define INT_MAX 1000000001
using namespace std;
typedef struct node{      //structure for binomial heap
node *sibling;
node *parent;
node *child;
int degree;
int value;
} node;

node * createbinomial();
node * union1(node *head1,node *head2);
node * insert(node *,int);
node * merge(node *head1,node *head2);
node * extractmin(node *);
int findmin(node *);
node * reverse(node *);
bool heapempty(node *);
void showHeap(node *x,int depth );
void showBinomialHeap(node *head);
int main()
{
    cout<<"Command Interface : 'i'- insert, 'S' -show heap, d- deletemin, '+' - if to show which element is deleted, '-' - to just delete without printing";
	cout<<"To exit from the Heap press 'q' "<<endl;
int print=0;
int t;
char x;
cin>>x;
node *head;    //header for a node in binomial heap
while((x!='\n' && x!='i' && x!='d' && x!='S' && x!='c' && x!='q') || x=='#')  //loopp to pass through every comment
	scanf("%c",&x);
if(x=='\n')
	cin>>x;
if(x=='c')     // checking to create binomial heap
	head=NULL;
if(x=='q')
{
		cout<<"Exit from Heap"<<endl;
		return 0;
}
cin>>x;
if(head!=NULL)   //if binomial heap is not creating but we start applying things on it
{
	cout<<"Make binomialheap first";
	return 0;
}
while(x!='q')    // loop until extracting from empty heap
{
	if(x=='i')    // if xis equal to i then insert t
	{
		cin>>t;
		head=insert(head,t);
	}
	else if(x=='-')
		print=0;
	else if(x=='+')
		print=1;
	else if(x=='d')   // if x quals d then extracing minimum and printing it
	{
		if(!heapempty(head))
		{
		int z=findmin(head);
		head=extractmin(head);
		if(print==1)
			cout<<"Minimum Extracted: "<<z<<endl;
		}
		else
			cout<<"Trying to Extract from Empty Heap";
	}
	else if(x=='S')   // if x equals S then showing binomial heap
		 showBinomialHeap(head);
	else if(x=='#')   // loop to pass comment
	{
		while(x!='\n')
		{
			scanf("%c",&x);
		}
	}
		cin>>x;
}
cout<<"Exit from Heap"<<endl;
return 0;

}


node * createbinomial()   //creating node for binomial heap
{
node *x=(node *)malloc(sizeof(node));
x->sibling=NULL;
x->parent=NULL;
x->child=NULL;
x->degree=0;
return x;
}



node * union1(node *head1,node *head2)   //making union of two binomial heap
{
node *head=merge(head1,head2);    //merging two binomial heap
node *x=head;
node *next=NULL;
if(x!=NULL)
	next=x->sibling;
node *ultimate=NULL;
if(next!=NULL)
	ultimate=next->sibling;
node *prev=NULL;
if(next==NULL || x==NULL)
	return x;
while(ultimate!=NULL)
{
	if(x->degree!=next->degree)
	{
		prev=x;
		x=x->sibling;
		next=next->sibling;
		if(next!=NULL)
			ultimate=next->sibling;
	}
	else if(x->degree==next->degree && x->degree==ultimate->degree)
	{
		prev=x;
		x=x->sibling;
		next=next->sibling;
		if(next!=NULL)
			ultimate=next->sibling;
	}
	else if(x->degree==next->degree && x->degree!=ultimate->degree)
	{
		if(x->value<=next->value)
		{
			x->degree=x->degree+1;
			next->parent=x;
			x->sibling=ultimate;
			next->sibling=x->child;
			x->child=next;
			next=x->sibling;
			if(next!=NULL)
				ultimate=next->sibling;
		}
		else
		{
			next->degree=next->degree+1;
			x->parent=next;
			x->sibling=next->child;
			next->child=x;
			if(prev!=NULL)
				prev->sibling=next;
			else
				head=next;
			x=next;
			next=x->sibling;
			if(next!=NULL)
				ultimate=next->sibling;
		}
	}
}
if(x->degree!=next->degree)
{
	prev=x;
	x=x->sibling;
	next=next->sibling;
	if(next!=NULL)
		ultimate=next->sibling;
}
else
{
	if(x->value<=next->value)
	{
		x->degree=x->degree+1;
		next->parent=x;
		x->sibling=ultimate;
		next->sibling=x->child;
		x->child=next;
	}
	else
	{
		next->degree=next->degree+1;
		x->parent=next;
		x->sibling=next->child;
		next->child=x;
		if(prev!=NULL)
			prev->sibling=next;
		else
			head=next;
	}
}
return head;
}


node * merge(node *head1,node *head2)
{
	node *head=NULL,*temp=NULL;
	node *h1=head1;
	node *h2=head2;
	if(h1!=NULL && h2!=NULL)
	{
		if(h1->degree <= h2->degree )
		{
			head=h1;
			h1=h1->sibling;
		}
		else
		{
			head=h2;
			h2=h2->sibling;
		}
	}
	else if(h1==NULL)
		return h2;
	else if(h2==NULL)
		return h1;
	temp=head;
	while(h1!=NULL || h2!=NULL)
	{
		if(h1!=NULL && h2!=NULL)
		{
			if(h1->degree <= h2->degree)
			{
				temp->sibling=h1;
				h1=h1->sibling;
				temp=temp->sibling;
			}
			else
			{
				temp->sibling=h2;
				h2=h2->sibling;
				temp=temp->sibling;
			}
		}
		else if(h1==NULL)
		{
			temp->sibling=h2;
			h2=h2->sibling;
			temp=temp->sibling;
		}
		else
		{
			temp->sibling=h1;
			h1=h1->sibling;
			temp=temp->sibling;
		}
	}
	return head;
}

node * insert(node * head,int key)   //inserting key in binomial heap
{
node *head1=createbinomial();
head1->value=key;
head=union1(head1,head);
return head;

}


node * extractmin(node * head)   //extracting minimum from binomial heap
{
if(head==NULL)
	return NULL;
node *t=head;
node *prev=NULL,*curr=NULL,*b=NULL;
int min=INT_MAX;
while(t!=NULL)
{
	if(t->value < min)
	{
		min=t->value;
		curr=t;
		b=prev;
	}
prev=t;
t=t->sibling;
}
node *head2=reverse(curr->child);
if(b==NULL)
{
	head=curr->sibling;
}
else
{
	b->sibling=curr->sibling;
}
free(curr);
return union1(head2,head);
}


int findmin(node * head)   //finding minimum in binomial heap
{
if(head==NULL)
	return -1;
node *t=head;
int min=INT_MAX;
while(t!=NULL)
{
	if(t->value < min)
	{
		min=t->value;
	}
t=t->sibling;
}
return min;

}

node * reverse(node *head)   //reversing the linked list
{
if(head==NULL)
	return NULL;
else if(head->sibling==NULL)
{
	head->parent=NULL;
	return head;
}
node * curr=head->sibling,*prev=head,*next=head->sibling->sibling;
prev->sibling=NULL;
while(next!=NULL)
{
	prev->parent=NULL;
	curr->sibling=prev;
	prev=curr;
	curr=next;
	next=curr->sibling;
}
prev->parent=NULL;
curr->sibling=prev;
curr->parent=NULL;
return curr;
}

bool heapempty(node *head)    //checking whether the heap is emty
{
	if(head==NULL)
		return 1;
	return 0;


}

void showBinomialHeap(node *head)    //printing binomial heap
{
    cout<<"Structure of binomial heap (rotated 90 degrees ccwise):\n";
    if(head==NULL)
        cout<<"Empty\n";
    else
        showHeap(head,0);
}

void showHeap(node *x,int depth )   //showing heap
{
    if(x->sibling!=NULL)
    {
        showHeap(x->sibling,depth);
    }
    if(x->parent==NULL)
        cout<<endl;
    if((x->child!=NULL) || x->parent==NULL)
    {
        if(depth>0)
        cout<<" ";
        for(int i=1;i<=depth;i++)
        {
            cout<<"\t";
        }
        cout<<"\t"<<x->value;
        if(x->child==NULL)
            cout<<endl<<endl;
    }
    else
        cout<<"\t"<<x->value<<endl;
    if(x->child!=NULL)
        showHeap(x->child,depth+1);

}





















