#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void Traverse_stack(struct node* top)
{
    struct node* temp=top;
    cout<<"Current Stack->\n";
    while(temp!=NULL)
    {
    cout<<temp->data<<"\n";
    temp=temp->next;
    }
}
struct node * push(struct node * top,int data)
{
    struct node * temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=top;
    top=temp;
    cout<<top->data<<" is pushed into the stack\n";
    Traverse_stack(top);
    return top;
}
struct node* pop(struct node* top)
{
    struct node * temp;
    temp=top;
    if(top==NULL)
    {
            cout<<"Stack is empty\n";

    }
    else
    {
      top=top->next;
      cout<<temp->data<<"is popped out of the stack\n";
      free(temp);
      Traverse_stack(top);
      return top;
  }
}
void TOP(struct node * top)
{
    if(top==NULL)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        cout<<"Top->"<<top->data<<"\n";
    }

}
bool isEmpty(struct node*top)
{

  if(top==NULL)
  {
      cout<<"Stack is empty\n";
      return true;
  }
  else
  {
      return false;
  }
}


int main()
{
    struct node * top=NULL;
    top=push(top,1);
    top=push(top,2);
    top=push(top,3);

    TOP(top);

    top=pop(top);
    top=pop(top);
    top=pop(top);
    isEmpty(top);


}
