// Removethe duplicate elements in the linked list
Node * removeDuplicates( Node *head) 
    {
      Node* temp1=head;

        Node* temp2=head->next;
        unordered_set<int> s;

        while(temp2!=NULL)

        {
            s.insert(temp1->data);
            if(s.find(temp2->data)!=s.end())
            {
                Node* del=temp2;
                 temp2=temp2->next;
                 temp1->next=temp2;
                 delete del;
                
            }

            else

            {
               temp1=temp1->next;
               temp2=temp2->next;

            }

        }

        return head;
    }
