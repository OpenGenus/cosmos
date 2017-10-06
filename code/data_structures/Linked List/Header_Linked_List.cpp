//Part of Cosmos by OpenGenus Foundation
//Contributed by Tushar Gautam (Tushark21)

#include <iostream>
#include <conio.h>

using namespace std;

int main(){

struct node{
	int info;
	node *next;
}*ptr,*head,*start;

int c=1,k=0,ele,data;

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

			ptr=new node;
			ptr->next=NULL;
			ptr->info=data;

			head->next=ptr;
			head=ptr;
			cout<<"Data Inserted\n";

		break;

		case 2:
			cout<<"Enter Item that you wnat to find\n";
			cin>>ele;

			ptr=start->next;
			int f;
			f=0;
			while(ptr!=NULL){
				k++;
				if(ptr->info==ele){
					f++;
					cout<<"Item Found at Node: "<<k<<"\n";
				}
				ptr=ptr->next;
			}
			if(f==0){
				cout<<"Item Not Found\n";
			}
			k=0;
		break;

		case 3:
			ptr=start->next;

			while(ptr!=NULL){
				cout<<ptr->info<<"->";
				ptr=ptr->next;
			}
			cout<<"\n";
		break;

		default:
			cout<<"Wrong Choice\nExiting...\n";
	}

}

getch();
return 0;
}
