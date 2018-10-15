/*
 * Part of Cosmos by OpenGenus Foundation
 */
#include <iostream>
using namespace std;
// Singly-Linked List Defined
struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
//Function to add nodes to the linked list
Node* TakeInput(int n)
{

    Node* head = NULL;
    //head of the Linked List
    Node* tail = NULL;
    //Tail of the Linked List

    while (n--)
    {

        int value;
        //data value(int) of the node
        cin >> value;

        //creating new node
        Node* newNode = new Node(value);

        //if the is no elements/nodes in the linked list so far.
        if (head == NULL)
            head = tail = newNode;               //newNode is the only node in the LL
        else   // there are some elements/nodes in the linked list
        {
            tail->next = newNode; // new Node added at the end of the LL
            tail = newNode; // last node is tail node
        }
    }
    return head;
}
Node* DetectCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return fast;
    }

    return NULL;
}
void RemoveCycle(Node* head, Node* intersect_Node)
{

    Node* slow = head;
    Node* prev = NULL;

    while (slow != intersect_Node)
    {
        slow = slow->next;
        prev = intersect_Node;
        intersect_Node = intersect_Node->next;
    }

    prev->next = NULL; //cycle removed
}
void PrintLL(Node* head)
{
    Node* tempPtr = head;
    // until it reaches the end
    while (tempPtr != NULL)
    {
        //print the data of the node
        cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    cout << endl;
}
int main()
{
    int n;
    //size of the linked list
    cin >> n;
    Node* head = TakeInput(n);
    //creating a cycle in the linked list
    // For n=5 and values 1 2 3 4 5
    head->next->next->next->next->next = head->next->next; // change this according tp your input
    // 1-->2-->3-->4-->5-->3-->4-->5-->3--> ...  and so on
    // PrintLL(head); Uncomment this to check cycle
    RemoveCycle(head, DetectCycle(head));
    PrintLL(head);
    return 0;
}
