/*
Here ListNode is class containing 'next' for next node, and value for
value at node.
*/

ListNode* mergeSort(ListNode* head) 
    {
      if (head==NULL||head->next==NULL)
      {
        return head;
      }

      ListNode* mid = getMid(head);

      ListNode* leftHalf = mergeSort(head);
      ListNode* rightHalf = mergeSort(mid);

      return merge(leftHalf, rightHalf);
    }
    
    ListNode* getMid(ListNode* head) 
    {
      ListNode* prev = NULL;
      ListNode *s_ptr = head;
      ListNode* f_ptr = head;
  
      while (f_ptr != NULL && f_ptr->next != NULL) 
      {
        prev = s_ptr;
        s_ptr = s_ptr->next;
        f_ptr = f_ptr->next->next;
      }
      
      prev->next = NULL;
      
      return s_ptr;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) 
    {
      ListNode* n_head = new ListNode(0);
      ListNode* rear = n_head;

      while (l1!=NULL && l2!=NULL) 
      {
        if (l1->value < l2->value) 
        {
          rear->next = l1;
          l1 = l1->next;
        } 
        else 
        {
          rear->next = l2;
          l2 = l2->next;
        }

        rear = rear->next;
      }

      if (l1 != NULL) 
      {
       rear->next = l1;
      }
  
      if (l2!= NULL) 
      {
        rear->next = l2;
      }
  
      return n_head->next;
    }
