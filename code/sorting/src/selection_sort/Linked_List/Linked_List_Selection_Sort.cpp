#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};


void swap (Node *ptr1, Node *ptr2)
{
    int temp = ptr1->data;
    ptr1->data = ptr2 -> data;
    ptr2 -> data = temp;
}

void selectionSort(struct Node *head)
{
    if(head==NULL)
        return;

    struct Node *ptr1 = head, *ptr2;
    struct Node *min;

    while(ptr1!=NULL)
    {
        min = ptr1;    // Initial the current node as minimum node
        ptr2 = ptr1->next;

        // Traverse for the unsorted part of the linked list 
        while(ptr2)
        {
            if(min->data > ptr2->data)
                min = ptr2;

            ptr2 = ptr2->next;
        }

        // Swap the minimum element with the current element
        swap(ptr1,min);
        ptr1 = ptr1->next;
    }
}

void printList(struct Node* head) {

    while (head != NULL) {
        cout<<head->data<<"-->";
        head = head->next;
    }

    cout<<"NULL";
}


/*
Sample Input
1 - Test cases
5 - Total number of elements to be inserted in linked list
23 2 34 5 1 - Adding the contents of the linked list

Sample Output
1 2 5 23 34
*/


int main() {
    int test,n,ele;
    cin >> test;

    while (test--) 
    {
        struct Node *head = NULL;
        struct Node *temp = NULL;
        cin>>n;

        while(n--)
        {
            cin>>ele;

            struct Node *ptr = new Node(ele);

            if(head==NULL)
                head = ptr;
            else
                temp->next = ptr;

            temp = ptr;
        }

        selectionSort(head);
        printList(head);
    }
    return 0;
}