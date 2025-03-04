// Floyd’s Cycle-Finding Algorithm: This is the fastest method and has been described below:
// Traverse linked list using two pointers. 
// Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
// If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop
ListNode* Solution::detectCycle(ListNode* A) {
  ListNode *fast=A, *slow=A;
  int flag=0;
  while(slow&&fast&&fast->next)
  {
      slow=slow->next;
      fast=fast->next->next;
      if(slow==fast)
      {
          flag=1;
          break;
      }
  }
  if(flag==0)
  return NULL;
 
  slow = A; 
    while (slow != fast) { 
        slow = slow->next; 
        fast = fast->next; 
    } 
  
    return slow;
   
}
