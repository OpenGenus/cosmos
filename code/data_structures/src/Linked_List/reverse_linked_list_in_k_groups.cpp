#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head) {
            return head; // No need to reverse if k <= 1 or the list is empty.
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev_group_tail = dummy;
        ListNode* current = head;

        while (true) {
            int count = 0;
            ListNode* group_start = current;
            ListNode* group_end = current;

            // Find the kth node in the group.
            while (count < k && group_end) {
                group_end = group_end->next;
                count++;
            }

            if (count < k || !group_end) {
                // If the remaining group has fewer than k nodes, stop.
                break;
            }

            ListNode* next_group_start = group_end->next;

            // Reverse the current group.
            ListNode* prev = next_group_start;
            ListNode* curr = group_start;
            while (curr != next_group_start) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            prev_group_tail->next = group_end;
            group_start->next = next_group_start;
            prev_group_tail = group_start;
            current = next_group_start;
        }

        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};

// Helper function to create a linked list from an array.
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list.
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createLinkedList(arr, 5);

    Solution solution;
    ListNode* reversed = solution.reverseKGroup(head, k);

    printLinkedList(reversed);

    return 0;
}
