// count the Number of Nodes n a Linked List
int getCount(struct Node* head){
  
        int cnt=0;
      Node *curr = head;
      while(curr != NULL){
          cnt++;
          curr = curr->next;
      }
      return cnt;
    }
