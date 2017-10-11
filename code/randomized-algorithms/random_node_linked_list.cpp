#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node* next;
};
 
// A reservoir sampling based function to print a random node from a linked list
void printRandom(struct Node *head)
{
    // If list is empty
    if (head == NULL)
       return;
 
    // Use a different seed value so that we don't get same result each time we run this program
    srand(time(NULL));
 
    // Initialize result as first node
    int result = head->key;
 
    // Iterate from the (k+1)th element to nth element
    struct Node *current = head;
    int n;
    for (n=2; current!=NULL; n++)
    {
        // change result with probability 1/n
        if (rand() % n == 0)
           result = current->key;
 
        // Move to next node
        current = current->next;
    }
 
    printf("Randomly selected key is %d\n", result);
}

/* Function to create a new node */
struct Node *newNode(int new_key)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the key  */
    new_node->key  = new_key;
    new_node->next =  NULL;
 
    return new_node;
}
 
 
/* Function to insert a node at the beginning of linked list */
void push(struct Node** head_ref, int new_key)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the key  */
    new_node->key  = new_key;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

int main()
{
    struct Node *head = NULL;
    int number_of_nodes;
    cin >> number_of_nodes;
    for (int i = 0; i < number_of_nodes; i++)
    {
        int x;
        cin >> x;
        push(&head, x);
    }
    
    printRandom(head);
 
    return 0;
}
