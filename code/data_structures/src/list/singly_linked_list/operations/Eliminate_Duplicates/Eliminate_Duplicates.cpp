//Eliminate duplicates from a sorted linked list

#include <iostream>

using namespace std;

// The node class structure
class node
{

public:

    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

//For taking input data
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    
    while(data!=-1)
    {
        node *newnode=new node(data);
        
         if(head==NULL)                
          {
            head=newnode;
            tail=newnode;
          }
          
        else
          {    
            tail->next=newnode;
            tail=newnode;
          }
        
         cin>>data;
    }
    
    return head;
}

// For printing the nodes
 void print(node *head)
  {
    node*temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
      cout<<endl;
}

//Eliminating the duplicate nodes function
 node* eliminate_duplicate(node* head)
  {
  
    if(head->next==NULL)
      return head;
   
   node* c=eliminate_duplicate( head->next);
   
       if(head->data==c->data)
       {
        return c;
       }
       
      else
      {
        head->next=c;
        return head;
      } 
}

 int main()
 {
    node* head=takeinput();
    head=eliminate_duplicate(head);
    print(head);
    return 0;    
}
