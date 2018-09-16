/*
 * Part of Cosmos by OpenGenus Foundation
 */


#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
// Reverse function for linkedlist
ListNode* reverseList(ListNode* A)
{
    ListNode* prev = NULL;
    while (A && A->next)
    {
        ListNode* temp = A->next;
        A->next = prev;
        prev = A;
        A = temp;
    }
    A->next = prev;
    return A;
}

int main()
{
    ListNode* head = new ListNode(5);
    ListNode* temp = head;            // Creating a linkedlist
    int i = 4;
    while (i > 0)                      //Adding values to the linkedlist
    {
        ListNode* t = new ListNode(i);
        temp->next = t;
        temp = temp->next;
        i--;
    }
    head = reverseList(head);            //calling reverse function
    return 0;
}
