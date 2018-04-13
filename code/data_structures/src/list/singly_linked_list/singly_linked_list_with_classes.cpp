#include <iostream>
class Node {
private:
    int _data;
    Node *_next;

public:
    Node()
    {
    }
    void setData(int Data)
    {
        _data = Data;
    }
    void setNext(Node *Next)
    {
        if (Next == NULL)
            _next = NULL;
        else
            _next = Next;
    }
    int Data()
    {
        return _data;
    }
    Node *Next()
    {
        return _next;
    }
};

class LinkedList {
private:
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
    }
    void insert_back(int data);
    void insert_front(int data);
    void init_list(int data);
    void print_List();
};

void LinkedList::print_List()
{
    Node *tmp = head;

    //Checking the list if there is a node or not.
    if (tmp == NULL)
    {
        std::cout << "List is empty\n";
        return;
    }

    //Checking only one node situation.
    if (tmp->Next() == NULL)
        std::cout << "Starting: " << tmp->Data() << "Next Value > NULL\n";
    else
        while (tmp != NULL)
        {
            std::cout << tmp->Data() << " > ";
            tmp = tmp->Next();
        }
}

/*inserting a value infront of the */
void LinkedList::insert_back(int data)
{
    //Creating a node
    Node *newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);

    //Creating a temporary pointer.
    Node *tmp = head;

    if (tmp != NULL)
    {
        while (tmp->Next() != NULL)
            tmp = tmp->Next();
        tmp->setNext(newNode);
    }
    else
        head = newNode;
}
/*Inserting a value in front of the head node.*/
void LinkedList::insert_front(int data)
{
    // creating a new node.
    Node *newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);

    newNode->setNext(head);
    head = newNode;
}
/*Initializing the list with a value.*/
void LinkedList::init_list(int data)
{
    //creating a node
    Node *newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);
    if (head != NULL)
        head = NULL;
    head = newNode;
}

int main()
{
    //Creating a list
    LinkedList list;

    //Initilizing it with 5
    list.init_list(5);
    list.insert_back(6);
    list.insert_front(4);
    list.print_List();
}
