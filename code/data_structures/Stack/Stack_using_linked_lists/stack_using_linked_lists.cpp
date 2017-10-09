//  Part of Cosmos by OpenGenus Foundation
//  Contributed by Riya Pannu on 08/10/17.

#include <iostream>
using namespace std;
//Defining individual node
struct node{
    int data;
    node* next;
};
//Defining class stack
class stack{
    node* top;
public:
    stack(){
        top=NULL;
    }
    void push();
    void pop();
    void show();
};
//Function to insert (push) items into the stack.
void stack::push(){
    int item;
    cout<<"Enter the data to be inserted \n";
    cin>>item;
    node* ptr=new node;
    ptr->data=item;
    if (top!=NULL)
    ptr->next=top;
    else ptr->next=NULL;
    top=ptr;
    cout<<item<<" inserted into the stack \n";
}
//Function to delete (pop) items from the stack.
void stack::pop(){
    if (top==NULL)
    {
        cout<<"Stack is empty";
        return;
    }
    int item;
    item=top->data;
    node* temp=top;
    top=top->next;
    delete temp;
    cout<<item<<" deleted \n";
}
//Function to display items present in the stack.
void stack::show(){
    if (top==NULL){
        cout<<"Stack is empty \n";
        return;
    }
    node* temp=top;
    while (temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    
}
//Main program.
int main() {
    stack s;
    int choice;
    do{
    cout<<"What do you want to do? Enter choice number. \n 1.Push \n 2.Pop \n 3.Show \n 4.Exit \n ";
    
    cin>>choice;
    if (choice==1)
        s.push();
    else if (choice==2)
        s.pop();
    else if (choice==3)
        s.show();
    else
        cout<<"Enter correct choice \n";
    } while (choice!=4);
    return 0;
}
