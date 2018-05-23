///
/// Part of Cosmos by OpenGenus Foundation
/// Contributed by: Pranav Gupta (foobar98)
/// Print Nth node of a singly linked list in the reverse manner
///

#include <iostream>
using namespace std;

// Linked list node
struct Node
{
public:

    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// Create linked list of n nodes
Node* takeInput(int n)
{
    // n is the number of nodes in linked list

    Node *head = NULL, *tail = NULL;

    int i = n;
    cout << "Enter elements: ";
    while (i--)
    {
        int data;
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}


// To find length of linked list
int length(Node *head)
{
    int l = 0;
    while (head != NULL)
    {
        head = head->next;
        l++;
    }
    return l;
}

void printNthFromEnd(Node *head, int n)
{
    // Get length of linked list
    int len = length(head);

    // check if n is greater than length
    if (n > len)
        return;

    // nth from end = (len-n+1)th node from beginning
    for (int i = 1; i < len - n + 1; i++)
        head = head->next;

    cout << "Nth node from end: " << head->data << endl;
}

int main()
{
    cout << "Enter no. of nodes in linked list: ";
    int x;
    cin >> x;
    Node *head = takeInput(x);

    cout << "Enter n (node from the end): ";
    int n;
    cin >> n;
    printNthFromEnd(head, n);
}
