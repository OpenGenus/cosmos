#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
}*head;


void reverse()
{
    node *prev = NULL;
    node *cur = head;
    node *next;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;
}

void push(int x)
{
    node *ptr = new node;
    ptr->data = x;
    ptr->next = NULL;

    if (head == NULL)
        head = ptr;

    else
    {
        ptr->next = head;
        head = ptr;
    }
}

void print()
{
    node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    push(2);
    push(3);
    push(4);
    push(5);

    cout << "\nOriginal list is : ";
    print();

    cout << "\nReversed list is : ";
    reverse();

    print();
    cout << "\n";
    return 0;

}
