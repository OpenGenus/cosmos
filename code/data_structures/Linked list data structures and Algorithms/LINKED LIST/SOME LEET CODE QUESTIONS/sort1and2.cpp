class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(struct Node *head) {
    if (!head || !(head->next))
        return head;
  
    //creating three dummy nodes to point to beginning of three linked lists. 
    Node* zeroD = new Node(0); 
    Node* oneD = new Node(0); 
    Node* twoD = new Node(0); 
  
    //initializing current pointers for three lists. 
    Node* zero = zeroD, *one = oneD, *two = twoD; 
  
    //traversing over the list with a pointer. 
    Node* curr = head; 
    while (curr) { 
        
        //we check data at current node and store the node in it's respective
        //list and update the link part of that list.
        if (curr->data == 0) { 
            zero->next = curr; 
            zero = zero->next; 
            curr = curr->next; 
        }
        else if (curr->data == 1) { 
            one->next = curr; 
            one = one->next; 
            curr = curr->next; 
        } 
        else { 
            two->next = curr; 
            two = two->next; 
            curr = curr->next; 
        } 
    } 
  
    //attaching the three lists containing 0s,1s and 2s respectively.
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 
  
    //updating the head of the list.
    head = zeroD->next; 
  
    //deleting dummy nodes.
    delete zeroD; 
    delete oneD; 
    delete twoD; 
  
    return head;
}

};