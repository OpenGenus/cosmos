
#include <iostream>

using namespace std;

//built node .... node = (data and pointer)
struct node
{
    int data;   //data item
    node* next; //pointer to next node

};

//built linked list
class linkedlist
{
private:
    node* head;     //pointer to the first node

public:
    linkedlist()        //constructor
    {
        head = NULL;    //head pointer points to null in the beginning == empty list

    }

//declaration
    void addElementFirst(int d);                //add element in the beginning (one node)
    void addElementEnd(int d);                  //add element in the end (one node)
    void addElementAfter(int d, int b);         //add element d before node b
    void deleteElement(int d);
    void display();                             //display all nodes

};

//definition
//1-Push front code
void linkedlist::addElementFirst(int d)
{
    node* newNode = new node;
    newNode->data = d;
    newNode->next = head;
    head = newNode;

}

//2-Push back code
void linkedlist::addElementEnd(int x)
{
    node* newNode = new node;
    node* temp = new node;
    temp = head;
    newNode->data = x;
    if (temp == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return;

    }


    while (temp->next != NULL)
        temp = temp->next;

    newNode->next = NULL;
    temp->next = newNode;

}

//3-Push after code
//head->10->5->8->NULL
//if d=5,key=2
//head->10->5->2->8->NULL
void linkedlist::addElementAfter(int d, int key)
{
    node* search = new node;    //search is pointer must search to points to the node that we want
    search = head;              //firstly search must points to what head points
    while (search != NULL)       //if linked list has nodes and is not empty
    {
        if (search->data == d)
        {
            node* newNode = new node;
            newNode->data = key;      //put key in data in newNode
            newNode->next = search->next;   //make the next of newNode pointer to the next to search pointer
            search->next = newNode;         //then make search pointer to the newNode
            return;                       //or break;

        }
        //else
        search = search->next;
    }

    if (search == NULL) //if linked list empty
        cout << "The link not inserted because there is not found the node " << d <<
            " in the LinkedList. " << endl;

}

//4-delete code
void linkedlist::deleteElement(int d)
{
    node* del;
    del = head;

    if (del == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;

    }

    if (del->data == d)    //if first element in linked list is the element that we want to delete ... or one element is what we want
    {
        head = del->next; //make head points to the next to del
        return;
    }

    //if(del->data!=d) .... the same
    if (del->next == NULL)
    {
        cout << "Is not here, So not deleted." << endl;
        return;
    }

    //if here more one nodes...one node points to another node ... bigger than 2 nodes .. at least 2 nodes
    while (del->next != NULL)
    {
        if (del->next->data == d)
        {
            node* tmp = del->next;
            del->next = del->next->next;
            delete tmp;
            return;

        }
        //else
        del = del->next;

    }
    cout << "Is not here, So not deleted." << endl;

}


//void linkedlist::display(node *head)
void linkedlist::display()
{
    int n = 0;                        //counter for number of node
    node* current = head;

    if (current == NULL)
        cout << "This is empty linked list." << endl;

    while (current != NULL)
    {
        cout << "The node data number " << ++n << " is " << current->data << endl;
        current = current->next;

    }
    cout << endl;

}


int main()
{
    linkedlist li;

    li.display();

    li.addElementFirst(25);  //head->25->NULL
    li.addElementFirst(36);  //head->36->25->NULL
    li.addElementFirst(49);  //head->49->36->25->NULL
    li.addElementFirst(64);  //head->64->49->36->25->NULL
    cout << "After adding in the first of linked list" << endl;
    li.display();
    //64
    //49
    //36
    //25


    cout << endl;

    cout << "After adding in the end of linked list" << endl;
    //head->64->49->36->25->NULL
    li.addElementEnd(25);  //head->25->NULL
    li.addElementEnd(36);  //head->25->36->NULL
    li.addElementEnd(49);  //head->25->36->49->NULL
    li.addElementEnd(64);  //head->25->36->49->64->NULL
    //head->64->49->36->25->25->36->49->64->NULL
    li.display();

    cout << endl;

    //head->64->49->36->25->25->36->49->64->NULL
    cout << "linked list after adding 10 after node that has data = 49" << endl;
    li.addElementAfter(49, 10);
    li.display();
    //head->64->49->10->36->25->25->36->49->64->NULL

    //head->64->49->10->36->25->25->36->49->64->NULL
    cout << "linked list after adding deleting 49" << endl;
    li.deleteElement(49);
    li.display();
    //head->64->10->36->25->25->36->49->64->NULL
    //Notice :delete the first 49 ... not permission for duplicates
    return 0;
}
