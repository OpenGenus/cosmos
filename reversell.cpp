//algo to reverse a linked list in c++
void ReversePrint(Node *head){
    if(head==NULL) return;
    else{
        ReversePrint(head->next);
        cout<<head->data<<endl;
    }
}
