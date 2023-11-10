class Solution
{
    public:
    Node* reverse( Node *head)
    {
        // code here
        // return head of reversed list
        Node *prevNode=NULL,*currNode=head,*nextNode=head;
        while(currNode!=NULL){
            nextNode=currNode->next;
            currNode->next=prevNode;
            prevNode=currNode;
            currNode=nextNode;
        }
        return prevNode;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        if(head==NULL)
        return NULL;
        head=reverse(head);
        
        Node* node=head;int carry=1;
        while(node!=NULL){
            int sum=carry+node->data;
            node->data=(sum%10);
            carry=sum/10;
            
            if(node->next==NULL) break;
            
            node=node->next;
        }
        
        if(carry) node->next=new Node(carry);
        
        return reverse(head);
        
    }
};
