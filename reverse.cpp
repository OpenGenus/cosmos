#include<iostream>
using namespace std;
class Node{
	public:
		int data;
	 struct Node *next;
};
class ReverseList{
	public:
		Node *head=NULL;
		void reverse();
		void insert(int);
		void display();
};
void ReverseList::insert(int item){ //inserting items at end of list
	Node *curr=new Node;
	
	curr->next=NULL;
	curr->data=item;
	if(head==NULL){
		head=curr;
		return;
	}
	struct Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=curr;
}
	

void ReverseList::reverse(){
	struct Node*p=head,*q,*r=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=r;
		r=q;
	}
	head=r;

}

void ReverseList::display(){
		if(head==NULL){
		cout<<"List is empty";
		return;
	}
	struct Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;

}
int main(){
	ReverseList l;
	int item,n,i;
	cout<<"enter the lenth of linked list"<<endl;
	cin>>n;
	for(i=1;i<=n;i++){
	cout<<"enter the item in the linked list"<<endl;
	cin>>item;
	l.insert(item);
	}
	
	l.reverse();
	l.display();
}
	


