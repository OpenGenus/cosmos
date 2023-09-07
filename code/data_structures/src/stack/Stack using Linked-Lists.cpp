#include<iostream>
using namespace std;

template <typename T>

class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

class Stack {
    Node<T> *head;
    	
    int size;							// number of elements prsent in stack
    
    public :
    
    Stack() {							//Constructor
      head = NULL; 
      size=0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return head==NULL;
    }
    
    void push(T element) {
        
        Node<T>* newNode=new Node<T>(element);		//Dynamically Allocation of new node 
              	
        if(head==NULL){
          newNode->next=NULL;			//If Stack is empty, just setting the pointer to next element to be NULL
        }
      	else{
          newNode->next=head;			//If Stack is not empty, insert the new element at the head
        }
        head=newNode;
        size++;
    }
    
    T pop() {
        // Handle exception if stack is empty
        if(head==NULL){
          cout<<"Stack is empty\n";
        }
        T elem= head->data;
        
        head=head->next;  				//Starts pointing to the next element in the stack
		size--;
      
        return elem;
    }
    
    T top() {

      	if(head==NULL){
          cout<<"Stack is empty\n";
        }
        else{
          return head->data;
    	}
    }
 
};

