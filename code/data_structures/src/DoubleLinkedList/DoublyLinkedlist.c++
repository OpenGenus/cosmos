Insertion of node 

There are 3 ways to add a node -

 At front - 

void Doubly_Linked_List :: add_front(int d)         // add front is a function to add element in front of LL
{
	// Creating new node
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = NULL;
	temp->next = front;

	// List is empty
	if(front == NULL)
		end = temp;
		
	else
		front->prev = temp;
		
	front = temp;
}

// in between nodes - 

void Doubly_Linked_List ::add_before(node *n, int d)       // add before is a function add element before a node
{
	node *temp;
	temp = new node();
	temp->data = d;
	temp->next = n;
	temp->prev = n->prev;
	n->prev = temp;

	//if node is to be inserted before first node
	if(n->prev == NULL)
		front = temp;
} 

// at the end -

void Doubly_Linked_List :: add_after(node *n, int d)        // add after adds a node at the end of LL
{
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = n;
	temp->next = n->next;
	n->next = temp;

	//if node is to be inserted after last node
	if(n->next == NULL)
		end = temp;
}

 Removal of a node

 Removal of a node is quite easy in Doubly linked list but requires special handling if the node to be deleted is first or last element of the list. 
Unlike singly linked list where we require the previous node, here only the node to be deleted is needed. We simply make the next of the previous node point to next of current node (node to be deleted) and prev of next node point to prev of current node.

void Doubly_Linked_List :: delete_node(node *n)
{	
	// if node to be deleted is first node of list
	if(n->prev == NULL)
	{
		front = n->next; //the next node will be front of list
		front->prev = NULL;
	}
	// if node to be deleted is last node of list
	else if(n->next == NULL)
	{
		end = n->prev;   // the previous node will be last of list
		end->next = NULL;
	}
	else
	{
		//previous node's next will point to current node's next
		n->prev->next = n->next;
		//next node's prev will point to current node's prev
		n->next->prev = n->prev;
	}
	//delete node
	delete(n);			
}
