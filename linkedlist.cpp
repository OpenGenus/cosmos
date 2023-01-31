// Given a reference (pointer to pointer) to the head
// of a list and an int, appends a new node at the end
void append(Node** head_ref, int new_data)
{

	// 1. allocate node
	Node* new_node = new Node();

	// Used in step 5
	Node *last = *head_ref;

	// 2. Put in the data
	new_node->data = new_data;

	// 3. This new node is going to be
	// the last node, so make next of
	// it as NULL
	new_node->next = NULL;

	// 4. If the Linked List is empty,
	// then make the new node as head
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	// 5. Else traverse till the last node
	while (last->next != NULL)
	{
		last = last->next;
	}

	// 6. Change the next of last node
	last->next = new_node;
	return;
}

// This code is contributed by anmolgautam818, arkajyotibasak
