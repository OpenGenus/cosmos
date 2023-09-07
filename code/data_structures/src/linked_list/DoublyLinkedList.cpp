#include<iostream>
using namespace std;
class linked
{
	public:
	linked *prev;
	int key;
	linked *next;
	void insert()
	{
		cin>>key;
	}
	void show()
	{
		cout<<key;
	}
};
int main()
{
	linked *start,*end,*node,*ptr,*p;
	int flag=0,ch,count=0,travel,pos;
	start=NULL;
	cout<<"Doubly Linked List code!"<<endl;
	do
	{
		cout<<"\n\n";
		cout<<"Option Menu"<<endl;
		cout<<"1) Creation of Linked List"<<endl;
		cout<<"2) Insertion at start"<<endl;
		cout<<"3) Insertion at end"<<endl;
		cout<<"4) Insertion at any point"<<endl;
		cout<<"5) Deletion at start"<<endl;
		cout<<"6) Deletion at end"<<endl;
		cout<<"7) Deletion at any point"<<endl;
		cout<<"8) Traversal from start"<<endl;
		cout<<"9) Traversal from end"<<endl;
		cout<<"10) Exit the program"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<"\n";
		switch(ch)
		{
			case 1:
				if(start==NULL)
				{
					cout<<"Creation of Linked List"<<endl;
					node = new linked;
					node->insert();
					node->next=NULL;
					node->prev=NULL;
					start=node;
					end=node;
					count++;
				}
				else
				{
					cout<<"Linked list is already created!"<<endl;
				}
				break;
			case 2:
				if(start!=NULL)
				{
					cout<<"Insertion at beginning"<<endl;
					node = new linked;
					node->insert();
					node->next=start;
					node->prev=NULL;
					start->prev=node;
					start=node;
					count++;
				}
				else
				{
					cout<<"Insertion is not possible because Linked list is not created!"<<endl;
				}
				break;
			case 3:
				if(start!=NULL)
				{
					cout<<"Insertion at end"<<endl;
					node = new linked;
					node->insert();
					node->prev=end;
					end->next=node;
					node->next=NULL;
					end=node;
					count++;
				}
				else
				{
					cout<<"Insertion not possible because linked list is not created"<<endl;
				}
				break;
			case 4:
				if(start!=NULL)
				{
					cout<<"Enter the position of insertion except 1 : ";
					cin>>pos;
					if(pos<=count)
					{
						node= new linked;
						node->insert();
						ptr=start;
						pos=pos-2;
						while(pos--)
						{
							ptr=ptr->next;
						}
						node->next=ptr->next;
						ptr->next=node;
						node->prev=ptr;
						count++;
					}
					else
					{
						cout<<"Position exceeds count which is impossible!!"<<endl;
					}
				}
				else
				{
					cout<<"Insertion not possible because Linked list is not created or is empty!"<<endl;
				}
				break;
			case 5:
				if(count>1)
				{
					cout<<"Deletion at start"<<endl;
					ptr=start;
					start=ptr->next;
					start->prev=NULL;
					delete ptr;
					count--;
				}
				else if(count==1)
				{
					ptr=start;
					start=NULL;
					end=NULL;
					delete ptr;
				}
				else if(count==0)
				{
					cout<<"Linked list is empty"<<endl;
				}
				else
				{
					cout<<"Deletion not possible because linked list is not created"<<endl;
				}
				break;
			case 6:
				if(count>1)
				{
					ptr=end;
					end=ptr->prev;
					end->next=NULL;
					delete ptr;
					count--;
				}
				else if(count==1)
				{
					ptr=start;
					start=NULL;
					end=NULL;
					delete ptr;
				}
				else if(count==0)
				{
					cout<<"Empty Linked list! Deletion not possible"<<endl;
				}
				else
				{
					cout<<"Linked list not created!! Deletion not possible!"<<endl;
				}
				break;
			case 7:
				if(start!=NULL)
				{
					cout<<"Enter position to delete!: ";
					cin>>pos;
					pos=pos-1;
					ptr=start;
					while(pos--)
					{
						ptr=ptr->next;
					}
					node=ptr->prev;
					p=ptr->next;
					node->next=p;
					p->prev=node;
					delete ptr;
					count--;
				}
				else
				{
					cout<<"Deletion not possible because Linked list does not exist"<<endl;
				}
				break;
			case 8:
				if(start!=NULL)
				{
					cout<<"Traversal from start"<<endl;
					ptr=start;
					travel=count;
					while(travel--)
					{
						ptr->show();
						cout<<"\t";
						ptr=ptr->next;
					}
				}
				else
				{
					cout<<"Cannot perform traversal because Linked list is not created or is empty!"<<endl;
				}
				break;
			case 9:
				if(start!=NULL)
				{
					cout<<"Traversal from end"<<endl;
					ptr=end;
					travel=count;
					while(travel--)
					{
						ptr->show();
						cout<<"\t";
						ptr=ptr->prev;
					}
				}
				break;
			case 10:
				flag=1;
				break;
			default: cout<<"Wrong choice! Exiting program"<<endl; flag=1;
		}
	}while(flag==0);
	cout<<"Thankyou for using the program"<<endl;
}
