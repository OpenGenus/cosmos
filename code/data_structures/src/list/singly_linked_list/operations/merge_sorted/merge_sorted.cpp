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



//Merge Function for linkedlist

ListNode* merge(ListNode* head1, ListNode* head2)
{

    ListNode* head3 = NULL;
    ListNode* temp3 = NULL;
    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            if (head3 == NULL)
                head3 = head1;
            if (temp3)
                temp3->next = head1;
            temp3 = head1;
            head1 = head1->next;
        }
        else
        {
            if (head3 == NULL)
                head3 = head2;
            if (temp3)
                temp3->next = head2;
            temp3 = head2;
            head2 = head2->next;
        }
    }
    if (head1)
    {
        if (head3)
            temp3->next = head1;
        else
            return head1;
    }
    if (head2)
    {
        if (head3)
            temp3->next = head2;
        else
            return head2;
    }
    return head3;
}


//Sort function for linkedlist following divide and conquer approach
ListNode* merge_sort(ListNode* A)
{
    if (A == NULL || A->next == NULL)
        return A;
    ListNode* temp = A;
    int i = 1;
    while (temp->next)
    {
        i++;
        temp = temp->next;

    }
    int d = i / 2;
    int k = 0;
    temp = A;
    while (temp)
    {
        k++;
        if (k == d)
            break;
        temp = temp->next;
    }
    ListNode* head1 = A;
    ListNode* head2 = temp->next;
    temp->next = NULL;
    head1 = merge_sort(head1);
    head2 = merge_sort(head2);
    ListNode* head3 = merge(head1, head2);
    return head3;
}

//function used for calling divide and xonquer algorithm
ListNode* sortList(ListNode* A)
{
    ListNode* head = merge_sort(A);
    return head;

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
    head = sortList(head);            //calling merge_sort function
    return 0;
}
