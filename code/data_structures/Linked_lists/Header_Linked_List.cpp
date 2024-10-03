//Part of Cosmos by OpenGenus Foundation
//Contributed by Tushar Gautam (Tushark21)

#include <iostream>
#include <conio.h>

using namespace std;

struct node{
	int info;
	node *next;
}*ptr,*head,*start;


//Function for creating new node and Inserting data in the node
struct node* insert(struct node* head,int data){
	ptr=new node;
	ptr->next=NULL;
	ptr->info=data;

	head->next=ptr;
	cout<<"Data Inserted\n";
	return ptr;
}

//Function for searching item in Linked List
int search(struct node* start,int item){
	ptr=start->next;
	int f,k;
	f=0;
	k=0;
	while(ptr!=NULL){
		k++;
		if(ptr->info==item){
			f++;
			cout<<"Item Found at Node: "<<k<<"\n";
		}
		ptr=ptr->next;
	}
	return f;
}

//Function for Printing the Linked List
void printLL(struct node* start){

	ptr=start->next;

	while(ptr!=NULL){
		cout<<ptr->info<<"->";
		ptr=ptr->next;
	}
	cout<<"\n";

}

int main(){

int c=1,k=0,item,data;

ptr=new node;
ptr->next=NULL;
start=head=ptr;

while(c<4 && c>0){
	cout<<"1.Insert\n2.Search Item\n3.Link List\n";
	cin>>c;

	switch(c){
		case 1:
			cout<<"Enter Data\n";
			cin>>data;
			
			head=insert(head,data);
		break;

		case 2:
			cout<<"Enter Item that you want to find\n";
			cin>>item;

			int f;
			f=search(start,item);
			if(f==0){
				cout<<"Item Not Found\n";
			}
		break;

		case 3:
			printLL(start);
		break;

		default:
			cout<<"Wrong Choice\nExiting...\n";
	}

}

getch();
return 0;
}
