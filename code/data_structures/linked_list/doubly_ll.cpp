#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
    int data;
    struct node *next,*prev;
};
struct node *head;
struct node *createNode(int x)
{
    struct node *nnode = (struct node *) malloc (sizeof(struct node));
    nnode->data = x;
    nnode->next = NULL;
    nnode->prev = NULL;
    return nnode;
}
void insertAtBeg(int x)
{
    struct node *nnode = createNode(x);
    if(head == NULL)
    {
        head = nnode;
        return;
    }
    head->prev = nnode;
    nnode->next = head;
    head = nnode;
}
void insertAtEnd(int x)
{
    struct node *temp = head;
    if(temp == NULL)
    {
        insertAtBeg(x);
        return;
    }
    struct node *nnode = createNode(x);
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nnode;
    nnode->prev = temp;
}
void insertAtPos(int x, int pos)
{
    int c = 0;
    struct node * current = head;
    if(current == NULL)
    {
        struct node *nnode = createNode(x);
        head = nnode;
        return;
    }
    while(current != NULL)
    {
        c++;
        if(c == pos-1)
        {
            struct node *nnode = createNode(x);
            nnode->next = current->next;
            nnode->prev = current;
            current->next = nnode;
            nnode->next->prev = nnode;
            return;
        }
        current = current->next;
    }
    cout<<"Position not found"<<endl;
}
void del(int pos)
{
    int count = 0;
    if(pos == 1)
    {
        struct node *temp = head;
        if(head->next == NULL)
        {
            delete(temp);
            head = NULL;
            return;
        }
        head = head->next;
        head->prev = NULL;
        delete(temp);
        return;
    }
    struct node *p = head;
    while(p != NULL)
    {
        count++;
        if(count == pos)
        {
            struct node *temp = p;
            if(p->next == NULL)
            {
                p->prev->next = NULL;
                delete(p);
                return;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete(temp);
            return;
        }
        p = p->next;
    }
    pos = 0;
}
void print()
{
    cout<<"Forward traverse"<<endl;
    struct node *temp = head;
    if(temp == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    while(temp != NULL)
    {
        cout<<temp->data<<" => ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void reversePrint()
{
    cout<<"Backward traverse"<<endl;
    struct node *temp = head;
    if(temp == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != NULL)
    {
        cout<<temp->data<<" => ";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    head = NULL;
    int x = 1, n, d, pos;
    cout<<"Enter 0 to exit"<<endl;
    cout<<"Enter 1 to insert node at beginning"<<endl;
    cout<<"Enter 2 to insert node at end"<<endl;
    cout<<"Enter 3 to insert node at specific position"<<endl;
    cout<<"Enter 4 to delete node"<<endl;
    cout<<"Enter 5 to print linked list"<<endl;
    cout<<"Enter 6 to print reverse linked list"<<endl;
    while(x)
    {
        cout<<"Enter case: ";
        cin>>n;
        switch(n)
        {
        case 0:
            exit(0);
        case 1:
            cout<<"Enter data to insert: "<<endl;
            cin>>d;
            insertAtBeg(d);
            break;
        case 2:
            cout<<"Enter data to insert: "<<endl;
            cin>>d;
            insertAtEnd(d);
            break;
        case 3:
            cout<<"Enter position where u want to insert: "<<endl;
            cin>>pos;
            cout<<"Enter data to insert: "<<endl;
            cin>>d;
            insertAtPos(d,pos);
            break;
        case 4:
            cout<<"Enter position u want to delete: "<<endl;
            cin>>pos;
            del(pos);
            break;
        case 5:
            print();
            break;
        case 6:
            reversePrint();
            break;
        default:
            cout<<"Not a valid case"<<endl;
        }
    }
    return 0;
}
