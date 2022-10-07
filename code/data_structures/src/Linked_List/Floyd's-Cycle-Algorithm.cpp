#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, 
                  int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, 
                  int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL) // here we traverse through second last node because temp pointing to second last node and 
                               // temp -> next will be NULL which will terminate loop there itself.
    {
        temp = temp->next;
    }

    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL) // here we traverse till last node and temp becomes NULL
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;            // slow pointer moves one node ahead.
        fast = fast->next->next;      // fast pointer moves two nodes ahead.

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

void deletion(node *&head, 
              int val)
{
    node *temp = head;
    while (temp -> next -> data != val)
    {
        temp = temp -> next;
    }

    node *todelete = temp -> next; // todelete points to the node to be deleted of value val.

    temp->next = temp -> next -> next;
}

void deleteHead(node *&head)
{
    node *todelete = head;
    head = head -> next; // head pointed to next node as head node.
    delete todelete;   // released memory = node deleted using a pointer todelete.
}

void makeCycle(node *&head, int val) // to create a cycle in linked list.
{
    node *temp = head;
    node *temp2;

    int count = 1;
    while (temp -> next != NULL)
    {
        if (count == val)
        {
            temp2 = temp;
        }

        temp = temp -> next;
        count++;
    }

    temp->next = temp2;
}

void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    } while (slow != fast);

    fast = head;

    while (slow -> next != fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = NULL;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    display(head);

    makeCycle(head, 3);

    cout << detectCycle(head) << endl;

    removeCycle(head);

    display(head);
}
