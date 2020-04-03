/**
	Code contributed by Hardev Khandhar for GirlScript Summer of Code 2020
	link: https://github.com/HardevKhandhar
*/

#include<iostream>
using namespace std;

// Declaring the structure of node
struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};

struct node *HEAD = NULL;

// Creating a node
node *createNode(int value)
{
    struct node *ptr;
    ptr = new(struct node);
    if(ptr == NULL)
    {
        cout << "Memory Not Allocated!" << endl;
        return 0;
    }
    else
    {
        ptr -> data = value;
        ptr -> lptr = NULL;
        ptr -> rptr = NULL;
        return ptr;
    }
}

// Insert node at the beginning of circular-doubly-linked-list
void insertAtFront()
{
    struct node *newNode;
    struct node *trav = HEAD;
    int value;
    cout << "Enter the value to be inserted: ";
    cin >> value;
    newNode = createNode(value);
    if(HEAD == NULL)
    {
        HEAD = newNode;
        newNode -> rptr = HEAD;
    }
    else
    {
        newNode -> lptr = NULL;
        newNode -> rptr = HEAD;

        while(trav -> rptr != HEAD)
        {
            trav = trav -> rptr;
        }
        trav -> rptr = newNode;
        HEAD = newNode;
    }
}

// Insert node at the end of circular-doubly-linked-list
void insertAtLast()
{
    struct node *newNode;
    struct node *trav;
    trav = HEAD;
    int value;
    cout << "Enter the value to be inserted: ";
    cin >> value;
    newNode = createNode(value);
    if(HEAD == NULL)
    {
        newNode -> lptr = NULL;
        HEAD = newNode;
        newNode -> rptr = HEAD;
        return;
    }

    else {
            while(trav -> rptr != HEAD)
            {
                trav = trav -> rptr;
            }
            trav -> rptr = newNode;
            newNode -> lptr = trav;
            newNode -> rptr = HEAD;
        }
}

// Insert node after a particular node in the circular-doubly-linked-list
void insertAtPosition(int x)
{
    struct node *trav;
    struct node *next;
    struct node *newNode;
    trav = HEAD;
    int value;
    cout << "Enter the value to be inserted: ";
    cin >> value;
    newNode = createNode(value);
    while(trav -> data != x && trav -> rptr != NULL)
    {
        trav = trav -> rptr;
    }
    if(trav == NULL)
    {
        cout << "Desired element not found!" << endl;
    }
    else
    {
        next = trav -> rptr;
        trav -> rptr = newNode;
        newNode -> rptr = next;
        newNode -> lptr = trav;
        next -> lptr = newNode;
    }
}

// Display the nodes of circular-doubly-linked-list
void display()
{
    struct node *ptr = HEAD;
    if(HEAD == NULL)
    {
        cout << "List is Empty!" << endl;
        return;
    }
    struct node *temp = HEAD;
    cout << "Elements of Doubly Linked List are: ";
    do{
        cout << ptr -> data << " ";
        ptr = ptr -> rptr;
    }
    while(ptr != HEAD);
    cout << endl;
}

// Delete front node from the list
void deleteAtFront()
{
    struct node *trav = HEAD;
    if(HEAD == NULL)
    {
        cout << "List is Empty!";
        return;
    }
    if(HEAD -> rptr == HEAD){
            cout << "Element " << HEAD -> data << " is removed." << endl;
            HEAD = NULL;
    }
    else {
            cout << "Element " << HEAD -> data << " is removed." << endl;
            while(trav -> rptr != HEAD){
                trav = trav -> rptr;
            }
            HEAD = HEAD -> rptr;
            HEAD -> lptr = NULL;
            trav -> rptr = HEAD;
    }
}

// Delete last node from the list
void deleteAtLast()
{
    struct node *trav;
    struct node *previous;
    trav = HEAD;
    if(HEAD == NULL){
        cout << "List is Empty!";
        return;
    }
    if(HEAD -> rptr == HEAD)
    {
        HEAD = NULL;
    }
    else {
         while(trav -> rptr != HEAD)
         {
             previous = trav;
             trav = trav -> rptr;
         }
             cout << "Element " << trav -> data << " is removed." << endl;
             previous = trav -> lptr;
             previous -> rptr = HEAD;
         }
}

// Delete node from a particular position in the list
void deleteAtPosition(int x)
{
    struct node *trav;
    struct node *previous;
    struct node *next;
    trav = HEAD;
    while(trav -> data != x && trav -> rptr != NULL)
    {
        previous = trav;
        trav = trav -> rptr;
    }
    if(trav == NULL)
    {
        cout << "Desired element not found!" << endl;
    }
    else
    {
        next = trav -> rptr;
        previous -> rptr = trav -> rptr;
        next -> lptr = previous;
    }
}

// Menu driven program
int main()
{
    int choice, nodes, position, element, i;
    cout << "**************************************" << endl;
    cout << "*    Circular Doubly Linked List     *" << endl;
    cout << "**************************************\n" << endl;
    while(1)
    {
        cout << "1. Insert node at the beginning" << endl;
        cout << "2. Insert node at the end" << endl;
        cout << "3. Insert node at given position" << endl;
        cout << "4. Delete node at front" << endl;
        cout << "5. Delete node at last" << endl;
        cout << "6. Delete node at given position" << endl;
        cout << "7. Display elements of linked list" << endl;
        cout << "8. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                insertAtFront();
                cout << endl;
                break;

            case 2:
                insertAtLast();
                cout << endl;
                break;

            case 3:
                int x;
                cout << "Enter the node information: ";
                cin >> x;
                insertAtPosition(x);
                cout << endl;
                break;

            case 4:
                deleteAtFront();
                cout << endl;
                break;

            case 5:
                deleteAtLast();
                cout << endl;
                break;

            case 6:
                int y;
                cout << "Enter the node information: ";
                cin >> y;
                deleteAtPosition(y);
                cout << endl;
                break;

            case 7:
                display();
                cout << endl;
                break;

            case 8:
                cout << "Exit" << endl;
                return 0;
                break;

            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    }
    return 0;
}

/**

**************************************
*    Circular Doubly Linked List     *
**************************************
1. Insert node at the beginning
2. Insert node at the end
3. Insert node at given position
4. Delete node at front
5. Delete node at last
6. Delete node at given position
7. Display elements of linked list
8. Exit

Enter your choice: 1
Enter the value to be inserted: 21

1. Insert node at the beginning
2. Insert node at the end
3. Insert node at given position
4. Delete node at front
5. Delete node at last
6. Delete node at given position
7. Display elements of linked list
8. Exit

Enter your choice: 1
Enter the value to be inserted: 52

1. Insert node at the beginning
2. Insert node at the end
3. Insert node at given position
4. Delete node at front
5. Delete node at last
6. Delete node at given position
7. Display elements of linked list
8. Exit

Enter your choice: 7
Elements of Doubly Linked List are: 52 21

1. Insert node at the beginning
2. Insert node at the end
3. Insert node at given position
4. Delete node at front
5. Delete node at last
6. Delete node at given position
7. Display elements of linked list
8. Exit

Enter your choice: 2
Enter the value to be inserted: 99

1. Insert node at the beginning
2. Insert node at the end
3. Insert node at given position
4. Delete node at front
5. Delete node at last
6. Delete node at given position
7. Display elements of linked list
8. Exit

Enter your choice: 3
Enter the node information: 21
Enter the value to be inserted: 45

1. Insert node at the beginning
2. Insert node at the end
3. Insert node at given position
4. Delete node at front
5. Delete node at last
6. Delete node at given position
7. Display elements of linked list
8. Exit

Enter your choice: 7
Elements of Doubly Linked List are: 52 21 45 99

1. Insert node at the beginning
2. Insert node at the end
3. Insert node at given position
4. Delete node at front
5. Delete node at last
6. Delete node at given position
7. Display elements of linked list
8. Exit

Enter your choice: 4
Element 52 is removed.

1. Insert node at the beginning
2. Insert node at the end
3. Insert node at given position
4. Delete node at front
5. Delete node at last
6. Delete node at given position
7. Display elements of linked list
8. Exit

Enter your choice: 5
Element 99 is removed.

1. Insert node at the beginning
2. Insert node at the end
3. Insert node at given position
4. Delete node at front
5. Delete node at last
6. Delete node at given position
7. Display elements of linked list
8. Exit

Enter your choice: 7
Elements of Doubly Linked List are: 21 45

*/
