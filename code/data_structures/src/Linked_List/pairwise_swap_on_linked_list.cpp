// Swaps the data of linked list in pairs
struct Node* pairwise_swap(struct Node* head)
{
   
    Node* curr = head;
    while(curr!= NULL && curr->next  != NULL){
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
    return head;
}
