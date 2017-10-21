
struct Node* SortedMerge(struct Node* a, struct Node* b) 
{
  struct Node* result = NULL;
   
  /* point to the last result pointer */
  struct Node** lastPtrRef = &result; 
   
  while(1) 
  {
    if (a == NULL) 
    {
      *lastPtrRef = b;
       break;
    }
    else if (b==NULL) 
    {
       *lastPtrRef = a;
       break;
    }
    if(a->data <= b->data) 
    {
      MoveNode(lastPtrRef, &a);
    }
    else
    {
      MoveNode(lastPtrRef, &b);
    }
   
    /* tricky: advance to point to the next ".next" field */
    lastPtrRef = &((*lastPtrRef)->next); 
  }
  return(result);
}
