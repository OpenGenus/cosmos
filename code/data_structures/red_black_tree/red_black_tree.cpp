#include <iostream>
#include <queue>
#include <memory>
using namespace std;

template<typename _Tp, class _DERIVE>
struct Node
{
    typedef std::shared_ptr<_DERIVE> p_node_type;
    _Tp data;
    p_node_type left, right;
    Node(_Tp d, p_node_type l = nullptr, p_node_type r = nullptr)
        :data(d), left(l), right(r) {}
};

template<typename _Tp>
struct RBNode : Node<_Tp, RBNode<_Tp>>
{
    typedef std::shared_ptr<RBNode> p_node_type;
    p_node_type parent;
    bool color;
    RBNode(_Tp d, p_node_type l = nullptr, p_node_type r = nullptr, p_node_type p = nullptr)
        :Node<_Tp, RBNode<_Tp>>(d, l, r), parent(p), color(false) {}
};

// Class to represent Red-Black Tree
template<typename _Tp, typename _Comp = std::less<_Tp>>
class RBTree
{
private:
    enum Color {RED, BLACK};
    typedef RBNode<_Tp> node_type;
    typedef std::shared_ptr<node_type> p_node_type;
    p_node_type root;
protected:
    void rotateLeft(p_node_type &, p_node_type &);
    void rotateRight(p_node_type &, p_node_type &);
    void fixViolation(p_node_type &, p_node_type &);
public:
    // Constructor
    RBTree() :root(nullptr) {}
    void insert(const _Tp &n);
    void inorder();
    void levelOrder();
};

// A recursive function to do level order traversal
void inorderHelper(std::shared_ptr<RBNode<int>> root)
{
    if (root == nullptr)
        return;
    
    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}

/* A utility function to insert a new node with given key
 in BST */
std::shared_ptr<RBNode<int>> BSTInsert(std::shared_ptr<RBNode<int>> root, std::shared_ptr<RBNode<int>> pt)
{
    /* If the tree is empty, return a new node */
    if (root == nullptr)
        return pt;
    
    /* Otherwise, recur down the tree */
    if (pt->data < root->data)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
 
    /* return the (unchanged) node pointer */
    return root;
}
 
// Utility function to do level order traversal
void levelOrderHelper(std::shared_ptr<RBNode<int>> root)
{
    if (root == nullptr)
        return;
    
    std::queue<std::shared_ptr<RBNode<int>>> q;
    q.push(root);
 
    while (!q.empty())
    {
        std::shared_ptr<RBNode<int>> temp = q.front();
        cout << temp->data << "  ";
        q.pop();
        
        if (temp->left != nullptr)
            q.push(temp->left);
        
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

template<typename _Tp, typename _Comp>
void RBTree<_Tp, _Comp>::rotateLeft(RBTree::p_node_type &root, RBTree::p_node_type &pt)
{
    RBTree::p_node_type pt_right = pt->right;
    
    pt->right = pt_right->left;
    
    if (pt->right != nullptr)
        pt->right->parent = pt;
 
    pt_right->parent = pt->parent;
    
    if (pt->parent == nullptr)
        root = pt_right;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
 
    else
        pt->parent->right = pt_right;
 
    pt_right->left = pt;
    pt->parent = pt_right;
}

template<typename _Tp, typename _Comp>
void RBTree<_Tp, _Comp>::rotateRight(RBTree::p_node_type &root, RBTree::p_node_type &pt)
{
    RBTree::p_node_type pt_left = pt->left;
    
    pt->left = pt_left->right;
    
    if (pt->left != nullptr)
        pt->left->parent = pt;
    
    pt_left->parent = pt->parent;
    
    if (pt->parent == nullptr)
        root = pt_left;
    
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    
    else
        pt->parent->right = pt_left;
    
    pt_left->right = pt;
    pt->parent = pt_left;
}

// This function fixes violations caused by BST insertion
template<typename _Tp, typename _Comp>
void RBTree<_Tp, _Comp>::fixViolation(RBTree::p_node_type &root, RBTree::p_node_type &pt)
{
    RBTree::p_node_type parent_pt = nullptr;
    RBTree::p_node_type grand_parent_pt = nullptr;
    
    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {
 
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
 
        /*  Case : A
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {
            
            RBTree::p_node_type uncle_pt = grand_parent_pt->right;
            
            /* Case : 1
             The uncle of pt is also red
             Only Recoloring required */
            if (uncle_pt != nullptr && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
 
            else
            {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
 
        /* Case : B
           Parent of pt is right child of Grand-parent of pt */
        else
        {
            RBTree::p_node_type uncle_pt = grand_parent_pt->left;
            
            /*  Case : 1
             The uncle of pt is also red
             Only Recoloring required */
            if ((uncle_pt != nullptr) && (uncle_pt->color == RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
 
    root->color = BLACK;
}
 
// Function to insert a new node with given data
template<typename _Tp, typename _Comp>
void RBTree<_Tp, _Comp>::insert(const _Tp &data)
{
    RBTree::p_node_type pt = std::make_shared<RBTree::node_type>(data);
    
    // Do a normal BST insert
    root = BSTInsert(root, pt);
 
    // fix Red Black Tree violations
    fixViolation(root, pt);
}
 
// Function to do inorder and level order traversals
template<typename _Tp, typename _Comp>
void RBTree<_Tp, _Comp>::inorder()     {  inorderHelper(root);}
template<typename _Tp, typename _Comp>
void RBTree<_Tp, _Comp>::levelOrder()  {  levelOrderHelper(root); }

// Driver Code
int main()
{
    RBTree<int> tree;
    
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
 
    cout << "Inoder Traversal of Created Tree\n";
    tree.inorder();
 
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
 
    return 0;
}
