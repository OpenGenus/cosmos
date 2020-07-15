#include <iostream> 
using namespace std; 
  
// Structure to represent an interval 
struct Interval 
{ 
    int low, high; 
}; 
  
// Structure to represent a node in Interval Search Tree 
struct ITNode 
{ 
    Interval *i;  // 'i' could also be a normal variable 
    int max; 
    ITNode *left, *right; 
}; 
  
// A utility function to create a new Interval Search Tree Node 
ITNode * newNode(Interval i) 
{ 
    ITNode *temp = new ITNode; 
    temp->i = new Interval(i); 
    temp->max = i.high; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 
  
// A utility function to insert a new Interval Search Tree Node 
// This is similar to BST Insert.  Here the low value of interval 
// is used tomaintain BST property 
ITNode *insert(ITNode *root, Interval i) 
{ 
    // Base case: Tree is empty, new node becomes root 
    if (root == NULL) 
        return newNode(i); 
  
    // Get low value of interval at root 
    int l = root->i->low; 
  
    // If root's low value is smaller, then new interval goes to 
    // left subtree 
    if (i.low < l) 
        root->left = insert(root->left, i); 
  
    // Else, new node goes to right subtree. 
    else
        root->right = insert(root->right, i); 
  
    // Update the max value of this ancestor if needed 
    if (root->max < i.high) 
        root->max = i.high; 
  
    return root; 
} 
  
// A utility function to check if given two intervals overlap 
bool doOVerlap(Interval i1, Interval i2) 
{ 
    if (i1.low <= i2.high && i2.low <= i1.high) 
        return true; 
    return false; 
} 
  
// The main function that searches a given interval i in a given 
// Interval Tree. 
Interval *overlapSearch(ITNode *root, Interval i) 
{ 
    // Base Case, tree is empty 
    if (root == NULL) return NULL; 
  
    // If given interval overlaps with root 
    if (doOVerlap(*(root->i), i)) 
        return root->i; 
  
    // If left child of root is present and max of left child is 
    // greater than or equal to given interval, then i may 
    // overlap with an interval is left subtree 
    if (root->left != NULL && root->left->max >= i.low) 
        return overlapSearch(root->left, i); 
  
    // Else interval can only overlap with right subtree 
    return overlapSearch(root->right, i); 
} 
  
void inorder(ITNode *root) 
{ 
    if (root == NULL) return; 
  
    inorder(root->left); 
  
    cout << "[" << root->i->low << ", " << root->i->high << "]"
         << " max = " << root->max << endl; 
  
    inorder(root->right); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create interval tree shown in above figure 
    Interval ints[] = {{15, 20}, {10, 30}, {17, 19}, 
        {5, 20}, {12, 15}, {30, 40} 
    }; 
    int n = sizeof(ints)/sizeof(ints[0]); 
    ITNode *root = NULL; 
    for (int i = 0; i < n; i++) 
        root = insert(root, ints[i]); 
  
    cout << "Inorder traversal of constructed Interval Tree is\n"; 
    inorder(root); 
  
    Interval x = {6, 7}; 
  
    cout << "\nSearching for interval [" << x.low << "," << x.high << "]"; 
    Interval *res = overlapSearch(root, x); 
    if (res == NULL) 
        cout << "\nNo Overlapping Interval"; 
    else
        cout << "\nOverlaps with [" << res->low << ", " << res->high << "]"; 
    return 0; 
} 