/*
 * Part of Cosmos by OpenGenus Foundation
 */

#include <iostream>

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

ListNode* rotate(ListNode* A, int B)
{
    int t = 0;
    ListNode* temp = A;
    ListNode* prev2 = NULL;
    while (temp)
    {
        ++t;
        prev2 = temp;
        temp = temp->next;
    }
    B = B % t;                    //count by which the list is to be rotated
    if (B == 0)
        return A;
    int p = t - B;
    ListNode* prev = NULL;
    ListNode* head = A;
    temp = A;
    for (int i = 1; i < p; i++)                     //reaching that point from where the list is to be rotated
    {
        prev = temp;
        temp = temp->next;
    }
    prev = temp;
    if (temp && temp->next)                    //rotating the list
        temp = temp->next;
    if (prev2)
        prev2->next = A;
    if (prev)
        prev->next = NULL;
    head = temp;

    return head;
}

int main()
{
    using namespace std;
    ListNode* head = new ListNode(5);
    ListNode* temp = head;            // Creating a linkedlist
    int i = 4;
    while (i > 0)                      //Adding values to the linkedlist
    {
        ListNode* t = new ListNode(i);
        temp->next = t;
        temp = temp->next;
        --i;
    }

    head = rotate(head, 2);            //calling rotate function
    return 0;
}
