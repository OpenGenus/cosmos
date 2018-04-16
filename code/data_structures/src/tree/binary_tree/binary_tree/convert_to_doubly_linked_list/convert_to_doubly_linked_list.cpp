/* Structure for tree and linked list
 *
 * struct Node
 * {
 *  int data;
 *  Node *left, *right;
 * };
 *
 */

// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list

template<typename Node>
void BToDLL(Node *root, Node **head_ref)
{
    if (!root)
        return;

    BToDLL(root->right, head_ref);
    root->right = *head_ref;

    if (*head_ref)
        (*head_ref)->left = root;
    *head_ref = root;

    BToDLL(root->left, head_ref);
}
