// Singly Linked List -->Love Babbar
// topics -->
/*
1) Insert at head
2) Insert at tail
3)  Insert at middle
4)  Insert at any Position
5)  Deletion Operation of Node by position
6)  Deletion of node by value
*/
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            // delete the object --> use the delete operation to the destructor
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for the value"
             << " " << value << endl;
    }
};
void insertathead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void insertattail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = tail->next;
}
void deletenode(node *&head, int position)
{

    // deleting start node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete (temp);
    }
    else
    {
        // deleting middle and end node
        node *curr = head;
        node *prev = NULL;
        int ct = 1;
        while (ct < position)
        {

            prev = curr;
            curr = curr->next;
            ct++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void deletebyvalue(node *&head, int value)
{
    node *curr = head;
    node *prev = NULL;
    if (value == curr->data)
    {
        prev = NULL;
        head = head->next;
        delete curr;
    }
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
        if (curr->data == value)
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            break;
        }
        else
        {
            continue;
        }
    }
}
void insertatposition(node *&head, node *&tail, int data, int position)
{
    node *nodetoinsert = new node(data);
    if (position == 1)
    {
        insertathead(head, data);
        return;
    }
    int ct = 1;
    node *temp = head;
    while (ct < position - 1)
    {
        ct++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insertattail(tail, data);
    }
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
bool floyd_loop_check_loop(node *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    node *s = head;
    node *fast = head->next;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        s = s->next;
        if (s == fast)
            return true;
    }
    return false;
}
int main()
{
    node *n1 = new node(34);
    node *head = n1;
    node *tail = n1;
    // cout<<n1->data<<" ";
    insertathead(head, 32);

    insertattail(tail, 36);
insertattail(tail,37);
insertattail(tail,39);
insertattail(tail,57);
    
    print(head);
    cout << endl;

// making a loop in the singly linked list
tail->next=head->next->next;
// removing the loop
if(floyd_loop_check_loop(head))
cout<<"Loop is present "<<endl;
else
cout<<"Lop is absent"<<endl;
    

    return 0;
}
