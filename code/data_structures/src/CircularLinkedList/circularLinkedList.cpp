#include <iostream>
using namespace std;

/**
 * A node will be consist of a int data &
 * a reference to the next node.
 * The node object will be used in making linked list
 */
class Node
{
public:
    int data;
    Node *next;
};

/**
 * Using nodes for creating a circular linked list.
 *
 */
class CircularList
{
public:
    /**
     * stores the reference to the last node
     */
    Node *last;

    /**
     * keeping predecessor reference while searching
     */

    Node *preLoc;

    /**
     * current node reference while searching
     */
    Node *loc;

    CircularList()
    {
        last = NULL;
        loc = NULL;
        preLoc = NULL;
    }

    /**
     * Checking if list empty
     */
    bool isEmpty()
    {
        return last == NULL;
    }

    /**
     * Inserting new node in front
     */
    void insertAtFront(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;

        if (isEmpty())
        {
            newnode->next = newnode;
            last = newnode;
        }
        else
        {
            newnode->next = last->next;
            last->next = newnode;
        }
    }

    /**
     * Inserting new node in last
     */
    void insertAtLast(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;

        if (isEmpty())
        {
            newnode->next = newnode;
            last = newnode;
        }
        else
        {
            newnode->next = last->next;
            last->next = newnode;
            last = newnode;
        }
    }

    /**
     * Printing whole list iteratively
     */
    void printList()
    {
        if (!isEmpty())
        {
            Node *temp = last->next;
            do
            {
                cout << temp->data;
                if (temp != last)
                    cout << " -> ";
                temp = temp->next;
            } while (temp != last->next);
            cout << endl;
        }
        else
            cout << "List is empty" << endl;
    }

    /**
     * Searching a value
     */
    void search(int value)
    {
        loc = NULL;
        preLoc = NULL;
        if (isEmpty())
            return;
        loc = last->next;
        preLoc = last;
        while (loc != last && loc->data < value)
        {
            preLoc = loc;
            loc = loc->next;
        }
        if (loc->data != value)
        {
            loc = NULL;
            // if(value > loc->data)
            //     preLoc = last;
        }
    }

    /**
     * Inserting the value in its sorted postion in the list.
     */
    void insertSorted(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;

        search(value);

        if (loc != NULL)
        {
            cout << "Value already exist!" << endl;
            return;
        }
        else
        {
            if (isEmpty())
                insertAtFront(value);
            else if (value > last->data)
                insertAtLast(value);
            else if (value < last->next->data)
                insertAtFront(value);
            else
            {
                newnode->next = preLoc->next;
                preLoc->next = newnode;
            }
        }
    }

    void deleteValue(int value)
    {
        search(value);
        if (loc != NULL)
        {
            if (loc->next == loc)
            {
                last = NULL;
            }
            else if (value == last->data)
            {
                preLoc->next = last->next;
                last = preLoc;
            }
            else
            {
                preLoc->next = loc->next;
            }
            delete loc;
        }
        else
            cout << "Value not found" << endl;
    }

    void destroyList()
    {
        Node *temp = last->next;
        while (last->next != last)
        {
            temp = last->next;
            last->next = last->next->next;
            delete temp;
        }
        delete last; // delete the only remaining node
        last = NULL;
    }
};

/**
 * Driver Code
 */
int main()
{

    CircularList *list1 = new CircularList();

    cout << "Initializing the list" << endl;
    list1->insertAtLast(2);
    list1->insertAtLast(3);
    list1->insertAtLast(4);
    list1->insertAtLast(6);
    list1->insertAtLast(8);

    list1->printList();

    cout << "Inserting 5 in the list sorted" << endl;
    list1->insertSorted(5);
    list1->printList();

    cout << "Deleting 3 from the list" << endl;
    list1->deleteValue(3);
    list1->printList();

    cout << "Destroying the whole list" << endl;
    list1->destroyList();
    list1->printList();
}