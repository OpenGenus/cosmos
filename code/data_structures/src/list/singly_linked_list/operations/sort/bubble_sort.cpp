///Bubble sort a linked list
#include <iostream>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node* next;

public:
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void print(node*head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
}

void insertAtHead(node*&head, int d)
{
    node* n = new node(d);
    n->next = head;
    head = n;
}

void insertInMiddle(node*&head, int d, int p)
{
    if (p == 0)
        insertAtHead(head, d);
    else
    {
        //assuming p<=length of LL
        int jump = 1;
        node*temp = head;
        while (jump <= p - 1)
        {
            jump++;
            temp = temp->next;
        }
        node*n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void takeInput(node*&head)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
}

///overloading to print LL
ostream& operator<<(ostream&os, node*head)
{
    print(head);
    cout << endl;
    return os;
}
istream& operator>>(istream&is, node*&head)
{
    takeInput(head);
    return is;
}

int length(node*head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

void bubbleSort(node*&head)
{
    int n = length(head);
    for (int i = 0; i < n - 1; i++) //n-1 times
    {
        node*current = head;
        node*prev = NULL;
        node*next;

        while (current != NULL && current->next != NULL)
        {
            if (current->data > current->next->data)
            {
                //swapping
                if (prev == NULL)
                {
                    next = current->next;
                    current->next = next->next;
                    next->next = current;

                    head = next;
                    prev = next;
                }
                else
                {
                    next = current->next;
                    prev->next = next;
                    current->next = next->next;
                    next->next = current;
                    prev = next;
                }
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
}


int main()
{
    node*head = NULL;
    cin >> head;
    cout << head;
    bubbleSort(head);
    cout << "BUBBLE SORTED LINKED LIST" << endl;
    cout << head;


    return 0;
}
