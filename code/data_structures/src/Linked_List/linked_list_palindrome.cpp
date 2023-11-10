bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    Node* additional = head;
    Node* slow = head, * fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* np = slow;
    Node* prev = slow, * curr = slow, * nex = slow;
    curr = prev->next;
    nex = curr->next;
    while (nex != NULL) {
        curr->next = nex->next;
        nex->next = prev->next;
        prev->next = nex;
        nex = curr->next;
        np = np->next;
    }
    slow = slow->next;
    while (slow != NULL) {
        if (additional->val != slow->val) {
            return false;
        }
        additional = additional->next;
        slow = slow->next;
    }
    return true;
}
