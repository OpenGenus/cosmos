void removeKthNodeFromEnd(LinkedList *head, int k) {
	LinkedList *temp=head;
	int n=0;
	while(temp->next){
		n++;
		temp=temp->next;
	}
	cout<<n;																									
	temp=head;
	if(n-k<0){
		head->value=head->next->value;
		head->next=head->next->next;
		return;
	}
	for(int i=1;i<=n-k;i++){
		temp=temp->next;
	}
  temp->next=temp->next->next;
}
