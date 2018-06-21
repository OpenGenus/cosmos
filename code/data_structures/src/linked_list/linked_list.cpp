#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <list>
#include <vector>


class Node
{
public:
    Node* next;
    int data;
public:
    Node(int data) : data(data) {}
};

class Linkedlist
{
private:
    Node* head;
public:
    void insertatpos(int p, int data)
    {
  
  //In case the list is empty, insert the value as the first element
		if(head == nullptr)
        {
			head = new Node(data);
			return;
		}
		int pos = 0;
		Node* current = head;        //Initialize current as the first element
		Node* h;
    
    //Traversing the entire list
		while(current->next != nullptr)
        {
			pos++;
			if(pos == p-1)
            {
				h = current->next;                      //Temporary object that points to the next node
				current->next = new Node(data);
				current->next->next = h;
			}
			current = current->next;
		}
	} 

    void append(int data)
    {
		if(head == nullptr)
        {
			head = new Node(data);
			return;
		}
		Node* current = head;
		while(current->next != nullptr)
        {
			current = current->next;
		}
		current->next = new Node(data);
	}

    void prepend(int data)
	{
		Node* nHead = new Node(data);
		nHead->next = head;
		head = nHead;
	}

    void delval(int data)
    {
		if(head == nullptr)
			return;
		Node* current = head;
		while(current->next != nullptr){
			if(current->next->data == data)
				current->next = current->next->next;
			current = current->next;
		}
	}
    void delatpos(int p){
		if(head == nullptr)
			return;
		Node* current = head;
		int pos = 0;
		while(current->next != nullptr){	
			pos++;	
			if(pos == p-1){
				current->next = current->next->next;
				return;
			}
			current = current->next;
		}
	}
	
    void display(){
		Node* current = head;
		while(current != nullptr){
			std::cout << current->data << " ->";
			current = current->next;
		}
	}
};




#endif