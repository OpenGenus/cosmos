/* Part of Cosmos by OpenGenus Foundation */
/* Contributed by Vaibhav Jain (vaibhav29498) */
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
struct node
{
    T info;
    node* pre;  // Holds the pointer to the previous node
    node* next; // Holds the pointer to the next node
    node();
};

template <typename T> node<T>::node()
{
    info = 0;
    pre = nullptr;
    next = nullptr;
}

template <class T>
class doubleLinkedList
{
    node<T>* head;
public:
    doubleLinkedList();
    int listSize();
    void insertNode(T, int);
    void deleteNode(int);
    void print();
    void reversePrint();
};

template <class T> doubleLinkedList<T>::doubleLinkedList()
{
    head = nullptr;
}

template <class T> int doubleLinkedList<T>::listSize()
{
    int i = 0;
    node<T> *ptr = head;

    // The loop below traverses the list to find out the size
    while (ptr != nullptr)
    {
        ++i;
        ptr = ptr->next;
    }
    return i;
}

template <class T> void doubleLinkedList<T>::insertNode(T i, int p)
{
    node<T> *ptr = new node<T>, *cur = head;
    ptr->info = i;
    if (cur == nullptr)
        head = ptr; // New node becomes head if the list is empty
    else if (p == 1)
    {
        // Put the node at the beginning of the list and change head accordingly
        ptr->next = head;
        head->pre = ptr;
        head = ptr;
    }
    else if (p > listSize())
    {
        // Navigate to the end of list and add the node to the end of the list
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = ptr;
        ptr->pre = cur;
    }
    else
    {
        // Navigate to 'p'th element of the list and insert the new node before it
        int n = p - 1;
        while (n--)
            cur = cur->next;
        ptr->pre = cur->pre;
        ptr->next = cur;
        cur->pre->next = ptr;
        cur->pre = ptr;
    }
    cout << "Node inserted!" << endl;
}

template <class T> void doubleLinkedList<T>::deleteNode(int p)
{
    if (p > listSize())
    {
        // List does not have a 'p'th node
        cout << "Underflow!" << endl;
        return;
    }
    node<T> *ptr = head;
    if (p == 1)
    {
        // Update head when the first node is being deleted
        head = head->next;
        head->pre = nullptr;
        delete ptr;
    }
    else if (p == listSize())
    {
        // Navigate to the end of the list and delete the last node
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->pre->next = nullptr;
        delete ptr;
    }
    else
    {
        // Navigate to 'p'th element of the list and delete that node
        int n = p - 1;
        while (n--)
            ptr = ptr->next;
        ptr->pre->next = ptr->next;
        ptr->next->pre = ptr->pre;
        delete ptr;
    }
    cout << "Node deleted!" << endl;
}

template <class T> void doubleLinkedList<T>::print()
{
    // Traverse the entire list and print each node
    node<T> *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->info << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

template <class T> void doubleLinkedList<T>::reversePrint()
{
    node<T> *ptr = head;

    // First, traverse to the last node of the list
    while (ptr->next != nullptr)
        ptr = ptr->next;

    // From the last node, use `pre` attribute to traverse backwards and print each node in reverse order
    while (ptr != nullptr)
    {
        cout << ptr->info << " <- ";
        ptr = ptr->pre;
    }
    cout << "NULL" << endl;
}

int main()
{
    doubleLinkedList<int> l;
    int m, i, p;
    while (true)
    {
        system("cls");
        cout << "1.Insert" << endl
             << "2.Delete" << endl
             << "3.Print" << endl
             << "4.Reverse Print" << endl
             << "5.Exit" << endl;
        cin >> m;
        switch (m)
        {
        case 1:
            cout << "Enter info and position ";
            cin >> i >> p;
            l.insertNode(i, p);
            break;
        case 2:
            cout << "Enter position ";
            cin >> p;
            l.deleteNode(p);
            break;
        case 3:
            l.print();
            break;
        case 4:
            l.reversePrint();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
        system("pause");
    }
    return 0;
}
