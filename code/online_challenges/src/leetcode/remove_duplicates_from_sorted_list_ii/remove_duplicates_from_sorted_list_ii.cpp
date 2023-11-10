/*
    link to problem:https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

    difficulty level: Medium
    approach:
    maintained a previous,current and next pointer in the linked list
    if next pointer and curr pointer is having same value then we increment the next pointer till they are unequal or nex becomes NULL

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *curr = head;
        ListNode *nex;
        ListNode *prev = NULL;
        while (curr != NULL)
        {
            nex = curr->next;
            cout << curr->val;
            if (nex != NULL and curr->val == nex->val)
            {
                while (nex != NULL && nex->val == curr->val)
                {
                    nex = nex->next;
                }
                if (nex != NULL)
                {
                    curr->next = nex->next;
                    swap(curr->val, nex->val);
                    // curr=curr->next;
                }
                else
                {
                    if (head == curr)
                        head = NULL;
                    if (prev != NULL)
                    {
                        prev->next = NULL;
                    }

                    curr = NULL;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};