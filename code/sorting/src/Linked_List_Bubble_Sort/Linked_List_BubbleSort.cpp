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

void bubbleSort(struct Node *head)
{
    if(head==NULL)
        return;

    bool flag=false;
    struct Node *ptr1;  //left pointer will always point to the start of the list
    struct Node *ptr2 = NULL;  //right pointer will always point to the end of the list

    while(true)
    {
        flag = false;
        ptr1 = head;

        while(ptr1->next != ptr2)
        {
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                flag = true; 
            } 
            ptr1 = ptr1->next;
        }

        //as the largest element is at the end of the list, assign that to ptr2 as there is no need to
        //check already sorted list

        ptr2 = ptr1;

        if(flag == false)
            break; 
    }
}

void printList(struct Node* head) {

    while (head != NULL) {
        cout<<head->data<<"-->";
        head = head->next;
    }

    cout<<"NULL";
}


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

        head = mergeSort(head);
        printList(head);
    }
    return 0;
}