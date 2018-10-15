#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

class node {
public:
    int data;
    node* next;

public:
    node(int d)
    {
        data = d;
        next = nullptr;
    }
};

void print(node*head)
{
    while (head != nullptr)
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
        node*temp = head;
        for (int jump = 1; jump < p; jump++)
            temp = temp->next;
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


///optimized recursive reverse
node*recReverse2(node*head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    node*newHead = recReverse2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    node*head = nullptr;
    cin >> head;
    cout << head;
    head = recReverse2(head);
    cout << "Reversed linked list: " << endl;
    cout << head;



    return 0;
}
