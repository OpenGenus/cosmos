#include<iostream>
using namespace std;
struct Student{
	int id;
	int marks;
	Student *next = NULL;
};
Student *first = NULL;
Student *last = NULL;

void display();
void insert_start();
void insert_end();
void insert_Before_Specific();
void insert_After_Specific();
void delete_start();
void delete_end();
void delete_Specific();
void delete_Before_Specific();
void delete_After_Specific();
void reverse_By_Iteration();
void reverse_By_Recursion(Student*);
void count_Number_Of_Nodes();
int count_Number_Of_Nodes_Recursion(Student*);
void sum_Of_All_Marks();
void Highest_Marks_In_List();
void Lowest_Marks_In_List();
bool search_In_LinkedList();
void insert_In_Sorted_List();
bool check_If_List_Is_Sorted();
void remove_Duplicates_In_LinkedList();
void reverse_Using_Sliding_Pointers();
void displayTheLinkedList();

int main(){
    display();
}

void display(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"0  - Exit \n";
    cout<<"1  - Insert At Start \n";
    cout<<"2  - Insert At End \n";
	cout<<"3  - Insert Before Specific \n";
	cout<<"4  - Insert After Specific \n";
	cout<<"5  - Delete Start \n";
	cout<<"6  - Delete End \n";
	cout<<"7  - Delete Before Specific \n";
	cout<<"8  - Delete After Specific \n";
    cout<<"9  - Reverse By Iteration\n";
    cout<<"10 - Reverse By Recursion \n";
	cout<<"11 - Count Number Of Nodes \n";
	cout<<"12 - Count Number Of Nodes Using Recursion \n";
	cout<<"13 - Sum of All Marks \n";
	cout<<"14 - Highest Marks In List \n";
	cout<<"15 - Lowest Marks In List \n";
	cout<<"16 - Search In LinkedList \n";
	cout<<"17 - Insert In Sorted List \n";
	cout<<"18 - Delete Specific Node \n";
	cout<<"19 - Check If ID of List Is Sorted \n";
	cout<<"20 - Remove Duplicates ID's In Linked List \n";
	cout<<"21 - Reverse Using Sliding Pointers \n";
    cout<<"22 - Display the Linked List \n";

    cout<<"Enter Your Option: ";
    int option;
    cin>>option;

    switch(option){
        case 0:
            break;
        case 1:
            insert_start();
            break;
        case 2:
            insert_end();
            break;
		case 3:
            insert_Before_Specific();
            break;	
        case 4:
            insert_After_Specific();
            break;
        case 5:
            delete_start();
            break;
        case 6:
            delete_end();
			break;
		case 7:
            delete_Before_Specific();
			break;
		case 8:
            delete_After_Specific();
			break;
		case 9:
            reverse_By_Iteration();
			break;
		case 10:
            reverse_By_Recursion(first);
			display();
			break;
		case 11:
            count_Number_Of_Nodes();
			break;
		case 12:
            cout<<count_Number_Of_Nodes_Recursion(first);
			display();
			break;
		case 13:
            sum_Of_All_Marks();
			break;
		case 14:
            Highest_Marks_In_List();
			break;
		case 15:
            Lowest_Marks_In_List();
			break;
		case 16:
            cout<<search_In_LinkedList();
			display();
			break;
		case 17:
            insert_In_Sorted_List();
			break;
		case 18:
            delete_Specific();
			break;
		case 19:
            cout<<check_If_List_Is_Sorted();
			display();
			break;
		case 20:
            remove_Duplicates_In_LinkedList();
			display();
			break;
		case 21:
            reverse_Using_Sliding_Pointers();
			break;
		case 22:
            displayTheLinkedList();
			break;
        default:
            cout<<"*** Invalid Option ***\n";
            cout<<"*** Enter Again ***\n";
            display();
    }
}
void insert_start(){
    cout<<"This is the function of insert_start \n";
	
	Student *current = new Student;
	cout<<"Enter ID: ";
	cin>>current->id;
	
	cout<<"Enter Marks: ";
	cin>>current->marks;
	
	if (first==NULL){
		first = last = current;
	}
	else{
		current->next = first;
		first = current;
	}
	display();
}
void insert_end(){
    cout<<"This is the function of insert_end \n";
	
	Student *current = new Student;
	cout<<"Enter ID: ";
	cin>>current->id;
	
	cout<<"Enter Marks: ";
	cin>>current->marks;
	
	if (first==NULL){
		first = last = current;
	}
	else{
		last->next = current;
		last = current;
	}
	display();
}
void insert_Before_Specific(){
	cout<<"This is the function of insert_Before_Specific \n";
	
	cout<<"Enter Key to insert before: ";
	int key;
	cin>>key;
	
	if (first->id==key){
		insert_start();
	}
	else{
		
		Student *p = first;
		Student *k = NULL;
		while((p->id!=key)&(p!=NULL))
		{
			k = p;
			p = p->next;
		}
		if (p->id==key){
			Student *current = new Student;
			cout<<"Enter ID: ";
			cin>>current->id;
			
			cout<<"Enter Marks: ";
			cin>>current->marks;
			
			current->next = p;
			k->next = current;
		}
		else{
			cout<<"Not found";
		}
	}
	display();
}
void insert_After_Specific(){
	cout<<"This is the function of insert_After_Specific \n";
	Student *current = new Student;
	
	cout<<"Enter ID To Insert After: ";
	int key;
	cin>>key;
	
	cout<<"Enter ID: ";
	cin>>current->id;
	
	cout<<"Enter Marks: ";
	cin>>current->marks;
	
	Student *p = first;
	
	while(p->id!=key && p->next!=NULL){
		p = p->next;
	}
	if (p->id==key){
		current->next = p->next;
		p->next = current;
	}
	else{
		cout<<"ID Not Found!!";
	}
	display();
}

void delete_start(){
    cout<<"This is the function of delete_start \n";
	
	if (first==NULL){
		cout<<"Linked List is Empty";
	}
	else{
		Student *p = first;
		first = first->next;
		delete p;
	}
    display();
}
void delete_end(){
    cout<<"This is the function of delete_end \n";
	
	if (first==NULL){
		cout<<"Linked List is Empty";
	}
	else{
		Student *p = first;
		
		while(p->next!=last)
		{
			p = p->next;
		}
		last = p;
		Student* d = p->next;
		p->next = NULL;
		delete d;
	}
    display();
}
void delete_Before_Specific(){
	cout<<"This is the function of delete_Before_Specific \n";
	
	cout<<"Enter ID To Delete Before: ";
	int key;
	cin>>key;
	
	Student *p = first;
	Student *q = NULL;
	Student *r = NULL;
	
	while(p->id!=key && p->next!=NULL){
		r = q;
		q = p;
		p = p->next;
	}
	if (p->id==key){
		r->next = q->next;
		delete q;
	}
	else{
		cout<<"ID Not Found!!";
	}
	display();
}
void delete_After_Specific(){
	cout<<"This is the function of delete_After_Specific \n";
	
	cout<<"Enter ID To Delete After: ";
	int key;
	cin>>key;
	
	Student *p = first;
	Student *q = first;
	
	while(p->id!=key && p->next!=NULL){
		q = p;
		p = p->next;
	}
	if (p->id==key){
		q->next = p->next;
		delete p;
	}
	else{
		cout<<"ID Not Found!!";
	}
	display();
}
void delete_Specific(){
	cout<<"This is the function of Delete Specific Node \n";
	
	if (first==NULL){
		cout<<"Linked List is Empty";
	}
	else{
		Student *p = first;
		Student *following = NULL;
		cout<<"Enter Node Number To Delete: ";
		int position;
		cin>>position;
		
		for (int i=0;i<position-1;i++){
			following = p;
			p = p->next;
		}
		following->next = p->next;
		delete p;
	}
	display();
}
void reverse_By_Iteration(){
	cout<<"This is the function of reverse_By_Iteration \n";
	int count = 0;
	
	//for counting number of nodes in linked list
	Student *p = first;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	//for copying linked list values into array
	int arr[count];
	if (first==NULL){
		cout<<"The List Is Empty";
	}
	else{
		int i = 0;
		while(p!=NULL)
		{
			arr[i] = p->id;
			p = p->next;
			i++;
		}
		//for copying array elements into linked list
		p = first;
		i--;
		while(p!=NULL)
		{
			p->id = arr[i--];
			p = p->next;
		}
	}
	display();
}
void reverse_By_Recursion(Student *p){

	if (p!=NULL){
		reverse_By_Recursion(p->next);
		cout<<"ID: "<<p->id<<endl;
		cout<<"Marks: "<<p->marks<<endl;
	}
}
void count_Number_Of_Nodes(){
	cout<<"This is the function of count_Number_Of_Nodes \n";
	Student *p = first;
	if (first==NULL){
		cout<<"The Number of Nodes are 0";
	}
	else{
		int count = 0;
		while(p!=NULL){
			count++;
			p = p->next;
		}
		cout<<"The Number of Nodes are: "<<count;
	}
	display();
}
int count_Number_Of_Nodes_Recursion(Student *p){
	
	if (p==NULL){
		return 0;
	}
	else
	{
		return count_Number_Of_Nodes_Recursion(p->next)+1;
	}
}
void sum_Of_All_Marks(){
	int sum = 0;
	Student *p = first;
	if (first==NULL){
		cout<<"Linked List Is Empty";
	}else{
		while(p!=NULL)
		{
			sum+=p->marks;
			p = p->next;
		}
	}
	cout<<"The Sum of Marks is: "<<sum;
	display();
	
}
void Highest_Marks_In_List(){
	int max = 0;
	Student *p = first;
	if (first==NULL){
		cout<<"Linked List Is Empty";
	}else{
		while(p!=NULL)
		{
			if(p->marks>max)
			{
				max = p->marks;
			}
			p = p->next;
		}
	}
	cout<<"The Highest Marks in List is: "<<max;
	display();
}
void Lowest_Marks_In_List(){
	
	Student *p = first;
	int min = p->marks;
	if (first==NULL){
		cout<<"Linked List Is Empty";
	}else{
		while(p!=NULL)
		{
			if(p->marks<min)
			{
				min = p->marks;
			}
			p = p->next;
		}
	}
	cout<<"The Lowest Marks in List is: "<<min;
	display();
}
bool search_In_LinkedList(){
	
	Student *p = first;
	cout<<"Enter ID to Search: ";
	int key;
	cin>>key;
	
	if (first==NULL){
		cout<<"Linked List Is Empty";
	}else{
		while(p!=NULL)
		{
			if(key == p->marks)
			{
				return true;
			}
			p = p->next;
		}
	}
	return false;
	display();
}
void insert_In_Sorted_List(){
	Student *p = first;
	Student *following = NULL;
	
	Student *current = new Student;
	
	cout<<"Enter ID: ";
	cin>>current->id;
	
	cout<<"Enter Marks: ";
	cin>>current->marks;
	
	while(p!=NULL && p->id<current->id)
	{
		following = p;
		p = p->next;
	}
	current->next = following->next;
	following->next = current;
	display();
}
bool check_If_List_Is_Sorted(){
	Student *p = first;
	if (first==NULL){
		cout<<"Linked List Is Empty";
	}else{
		int x = p->id;
		while(p!=NULL)
		{
			if(p->id<x){
				return false;
			}
			x = p->id;
			p = p->next;
		}
		return true;
	}
	display();
}
void remove_Duplicates_In_LinkedList(){
	Student *p = first;
	Student *q = p->next;
	
	while(q!=NULL){
		if (p->id!=q->id){
			p = q;
			q = q->next;
		}
		else{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
	display();
}
void reverse_Using_Sliding_Pointers(){
	Student *p = first;
	Student *q = NULL;
	Student *r = NULL;
	
	while(p!=NULL){
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
	
	display();
}
void reverseOnlyRunTime(){
	Student *p = first;
	Student *q = first;
	Student *r = NULL;
	if (first==NULL){
		cout<<"Linked List Is Empty";
	}else{
		while(p!=NULL)
		{
			while(q->next!=r){
				q = q->next;
			}
			cout<<q->data<<" ";
			r = q;
			p = p->next;
		}
	}
}
void displayTheLinkedList(){
	cout<<"This is the function of display_The_LinkedList \n";
	
	Student *p = first;
	if (first==NULL){
		cout<<"Linked List Is Empty";
	}else{
		while(p!=NULL)
		{
			cout<<"ID: "<<p->id<<endl;
			cout<<"Marks: "<<p->marks<<endl;
			p = p->next;
		}
	}
	display();
}