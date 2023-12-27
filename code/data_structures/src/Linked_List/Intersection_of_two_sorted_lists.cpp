Node* findIntersection(Node* head1, Node* head2)
{
    
    if(head1==NULL or head2==NULL) return NULL;
    
    if(head1->data==head2->data) 
    {
        head1->next=findIntersection(head1->next,head2->next);
        return head1;
    }
    
    else if(head1->data>head2->data) 
    return findIntersection(head1,head2->next);
    
    else return findIntersection(head1->next,head2);
}
