// Reverse a linked list
// 3,4,2,1,5
// reverse- 5,1,2,4,3

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a, n) for (int i = a; i < n; i++)
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
            delete next;
        }
        cout << "the deleted value is" << value << endl;
    }
};


void insertathead(node *&head, int data)
{
    node *temp = head;
    node *nodetoinsert = new node(data);
    nodetoinsert->next = temp;
    head = nodetoinsert;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



void deletenode(node *&head, int position)
{
    // empty list
    if (head == NULL)
    {
        return;
    }
    // single node
    if (position == 1)
    {
        node *temp = head;
        delete temp;
    }
    int ct = 1;
    node *prev = head;
    node *curr = head;
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

int length(node *&head)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->next == NULL)
    {
        return 1;
    }
    int ct = 1;
    return 1 + length(head->next);
}

// hare and tortoise
node *approach2(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    if (head->next->next == NULL)
    {
        return head->next;
    }
    else
    {

        node *tortoise = head;
        node *hare = head->next;

       while (hare!=NULL)
       {
        hare=hare->next;
        if(hare->next==NULL){
            hare=hare->next;
        }
        tortoise=tortoise->next;  
       }
       
        return tortoise;
    }
}
node *approach1(node *head, int length)
{
    int middleposition = ((length) / 2) + 1;
    node *curr = head;
    int ct = 1;
    while (ct < middleposition)
    {
        curr = curr->next;
        ct++;
    }
    return curr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *n1 = new node(6);

    node *head = n1;
    insertathead(head, 5);
    insertathead(head, 4);
    insertathead(head, 3);

    print(head);

    cout << endl;
    int a = length(head);
    // node*middleoflinkedlist=approach1(head,a);
    node *middleoflinkedlist = approach2(head);
    cout << middleoflinkedlist->data << " " << endl;
    return 0;
}
