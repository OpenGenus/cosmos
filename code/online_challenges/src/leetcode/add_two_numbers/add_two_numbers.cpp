class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int c=0;
        int sum=0;
        int placevalue=1;
        ListNode* l;
        ListNode* p=new ListNode(0);
        l=p;
        while(l1 && l2)
      {
         int k=(l1->val +l2->val+c) %10;
            c= (l1->val +l2->val+c)/10;
            l1=l1->next;
            l2=l2->next;
            sum+=k*placevalue;
            placevalue*=10;
            l->next=new ListNode(k);
            l=l->next;
      }
        while(l1)
        {
            int k=(l1->val+c) %10;
            c= (l1->val+c)/10;
            l1=l1->next;
            sum+=k*placevalue;
            placevalue*=10;
            l->next=new ListNode(k);
            l=l->next;
        }
        while(l2)
        {
            int k=(l2->val+c) %10;
            c= (l2->val+c)/10;
            l2=l2->next;
            sum+=k*placevalue;
            placevalue*=10;
            l->next=new ListNode(k);
            l=l->next;
        }
        if(c)
           l->next=new ListNode(c);  
    return p->next;
    }
};