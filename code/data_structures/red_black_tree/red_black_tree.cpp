#include <iostream>
#include <memory>
#include <cassert>
#include <string>
#include <stack>
using namespace std;

template<typename _Type, class _Derivative>
struct Node
{
    typedef std::shared_ptr<_Derivative> SPNodeType;
    _Type data;
    SPNodeType left, right;
    Node(_Type d, SPNodeType l = nullptr, SPNodeType r = nullptr)
        :data(d), left(l), right(r) {}
};

template<typename _Type>
struct RBNode :Node<_Type, RBNode<_Type>>
{
    enum class Color
    {
        RED,
        BLACK
    };

    typedef std::shared_ptr<RBNode> SPNodeType;
    SPNodeType parent;
    Color color;
    RBNode(_Type d, SPNodeType l = nullptr, SPNodeType r = nullptr, SPNodeType p = nullptr)
        :Node<_Type, RBNode<_Type>>(d, l, r), parent(p), color(Color::RED) {}
};

// Class to represent Red-Black Tree
template<typename _Type, typename _Compare = std::less<_Type>>
class RBTree
{
private:
    typedef RBNode<_Type> NodeType;
    typedef std::shared_ptr<NodeType> SPNodeType;
    typedef typename RBNode<_Type>::Color Color;

public:
    // Constructor
    RBTree() :root_(nullptr), sentinel_(std::make_shared<NodeType>(0)), compare_(_Compare()) {
        sentinel_->left = sentinel_;
        sentinel_->right = sentinel_;
        sentinel_->parent = sentinel_;
        sentinel_->color = Color::BLACK;
        root_ = sentinel_;
    }

    void insert(_Type const &n);

    void erase(_Type const &n);

    SPNodeType const find(_Type const &);

    std::string preOrder() const;

    std::string inOrder() const;

private:
    SPNodeType root_;
    SPNodeType sentinel_;
    _Compare compare_;

    SPNodeType &insert(SPNodeType &root, SPNodeType &pt);

    SPNodeType &_find(_Type const &data);

    void rotateLeft(SPNodeType &);

    void rotateRight(SPNodeType &);

    void fixViolation(SPNodeType &);

    SPNodeType successor(SPNodeType const &);

    SPNodeType &sibling(SPNodeType const &);

    bool isLeftChild(SPNodeType const &);

    bool isRightChild(SPNodeType const &);

    void deleteOneNode(SPNodeType &);

    void deleteCase1(SPNodeType const &);

    void deleteCase2(SPNodeType const &);

    void deleteCase3(SPNodeType const &);

    void deleteCase4(SPNodeType const &);

    void deleteCase5(SPNodeType const &);

    void deleteCase6(SPNodeType const &);
};

// Function to insert a new node with given data
template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::insert(_Type const &data)
{
    SPNodeType pt = std::make_shared<NodeType>(data, sentinel_, sentinel_);

    // Do a normal BST insert
    root_ = insert(root_, pt);

    // fix Red Black Tree violations
    fixViolation(pt);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::erase(_Type const &data) {
    SPNodeType delete_node = _find(data);

    // found
    if (delete_node != sentinel_)
    {
        // only root
        if (delete_node->left == sentinel_)
        {
            deleteOneNode(delete_node);
        }
        else
        {
            SPNodeType smallest = successor(delete_node);
            swap(delete_node->data, smallest->data);
            deleteOneNode(smallest);
        }
    }
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteOneNode(SPNodeType &pt) {
    SPNodeType child = pt->left != sentinel_ ? pt->left : pt->right;
    if (pt->parent == sentinel_)
    {
        root_ = child;
        root_->parent = sentinel_;
        root_->color = Color::BLACK;
    }
    else
    {
        if (isLeftChild(pt))
        {
            pt->parent->left = child;
        }
        else
        {
            pt->parent->right = child;
        }
        child->parent = pt->parent;
        if (pt->color == Color::BLACK)
        {
            if (child->color == Color::RED)
            {
                child->color = Color::BLACK;
            }
            else
            {
                deleteCase1(child);
            }
        }
    }
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::find(_Type const &data)->SPNodeType const {
    SPNodeType pt = _find(data);

    return pt != sentinel_ ? pt : nullptr;
}

template<typename _Type, typename _Compare>
std::string
RBTree<_Type, _Compare>::preOrder() const {
    if (root_ == sentinel_)
    {
        return {};
    }
    std::string elem{};
    std::stack<SPNodeType> st{};
    st.push(root_);
    elem.append(std::to_string(st.top()->data));
    while (!st.empty())
    {
        while (st.top()->left != sentinel_)
        {
            elem.append(std::to_string(st.top()->left->data));
            st.push(st.top()->left);
        }
        while (!st.empty() && st.top()->right == sentinel_)
            st.pop();
        if (!st.empty())
        {
            elem.append(std::to_string(st.top()->right->data));
            auto temp = st.top();
            st.pop();
            st.push(temp->right);
        }
    }

    return elem;
}

template<typename _Type, typename _Compare>
std::string
RBTree<_Type, _Compare>::inOrder() const {
    if (root_ == sentinel_)
    {
        return {};
    }
    std::string elem{};
    std::stack<SPNodeType> st{};
    st.push(root_);
    while (!st.empty())
    {
        while (st.top()->left != sentinel_)
            st.push(st.top()->left);
        while (!st.empty() && st.top()->right == sentinel_)
        {
            elem.append(std::to_string(st.top()->data));
            st.pop();
        }
        if (!st.empty())
        {
            elem.append(std::to_string(st.top()->data));
            auto temp = st.top();
            st.pop();
            st.push(temp->right);
        }
    }

    return elem;
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::insert(SPNodeType &root, SPNodeType &pt)->SPNodeType &
{
    /* If the tree is empty, return a new node */
    if (root == sentinel_)
    {
        pt->parent = root->parent;

        return pt;
    }

    /* Otherwise, recur down the tree */
    if (compare_(pt->data, root->data))
    {
        root->left = insert(root->left, pt);
        root->left->parent = root;
    }
    else if (compare_(root->data, pt->data))
    {
        root->right = insert(root->right, pt);
        root->right->parent = root;
    }
    else
    {
        pt->parent = root->parent;
        pt->left = root->left;
        pt->right = root->right;
        pt->color = root->color;
    }

    /* return the (unchanged) node pointer */
    return root;
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::_find(_Type const &data)->SPNodeType &
{
    SPNodeType pt = std::make_shared<NodeType>(data);
    std::stack<SPNodeType> st{};
    st.push(root_);
    while (!st.empty())
    {
        if (compare_(st.top()->data, pt->data) == compare_(pt->data, st.top()->data))
        {
            return st.top();
        }
        while (st.top()->left != sentinel_)
        {
            st.push(st.top()->left);
            if (compare_(st.top()->data, pt->data) == compare_(pt->data, st.top()->data))
            {
                return st.top();
            }
        }
        while (!st.empty() && st.top()->right == sentinel_)
            st.pop();
        if (!st.empty())
        {
            if (compare_(st.top()->data, pt->data) == compare_(pt->data, st.top()->data))
            {
                return st.top();
            }
            else
            {
                SPNodeType &temp = st.top();
                st.pop();
                st.push(temp->right);
            }
        }
    }

    return sentinel_;
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::rotateLeft(SPNodeType &pt)
{
    SPNodeType pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != sentinel_)
    {
        pt->right->parent = pt;
    }

    pt_right->parent = pt->parent;

    if (pt->parent == sentinel_)
    {
        root_ = pt_right;
    }
    else if (pt == pt->parent->left)
    {
        pt->parent->left = pt_right;
    }
    else
    {
        pt->parent->right = pt_right;
    }

    pt_right->left = pt;
    pt->parent = pt_right;
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::rotateRight(SPNodeType &pt)
{
    SPNodeType pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != sentinel_)
    {
        pt->left->parent = pt;
    }

    pt_left->parent = pt->parent;

    if (pt->parent == sentinel_)
    {
        root_ = pt_left;
    }
    else if (pt == pt->parent->left)
    {
        pt->parent->left = pt_left;
    }
    else
    {
        pt->parent->right = pt_left;
    }

    pt_left->right = pt;
    pt->parent = pt_left;
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::successor(SPNodeType const &pt)->SPNodeType {
    SPNodeType child = sentinel_;
    if (pt->left != sentinel_)
    {
        child = pt->left;
        while (child->right != sentinel_)
            child = child->right;
    }
    else if (pt->right != sentinel_)
    {
        child = pt->right;
        while (child->left != sentinel_)
            child = child->left;
    }

    return child;
}

// This function fixes violations caused by BST insertion
template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::fixViolation(SPNodeType &pt)
{
    SPNodeType parent_pt = sentinel_;
    SPNodeType grand_parent_pt = sentinel_;

    while (pt->color == Color::RED && pt->parent->color == Color::RED)
    {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /*  Case : A
         Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {
            SPNodeType uncle_pt = grand_parent_pt->right;

            /* Case : 1
             The uncle of pt is also red
             Only Recoloring required */
            if (uncle_pt->color == Color::RED)
            {
                grand_parent_pt->color = Color::RED;
                parent_pt->color = Color::BLACK;
                uncle_pt->color = Color::BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                 pt is right child of its parent
                 Left-rotation required */
                if (pt == parent_pt->right)
                {
                    rotateLeft(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                 pt is left child of its parent
                 Right-rotation required */
                rotateRight(grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
        /* Case : B
         Parent of pt is right child of Grand-parent of pt */
        else
        {
            SPNodeType uncle_pt = grand_parent_pt->left;

            /*  Case : 1
             The uncle of pt is also red
             Only Recoloring required */
            if (uncle_pt->color == Color::RED)
            {
                grand_parent_pt->color = Color::RED;
                parent_pt->color = Color::BLACK;
                uncle_pt->color = Color::BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                 pt is left child of its parent
                 Right-rotation required */
                if (pt == parent_pt->left)
                {
                    rotateRight(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                 pt is right child of its parent
                 Left-rotation required */
                rotateLeft(grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root_->color = Color::BLACK;
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::sibling(SPNodeType const &n)->SPNodeType & {
    return n->parent->left != n ? n->parent->left : n->parent->right;
}

template<typename _Type, typename _Compare>
bool
RBTree<_Type, _Compare>::isLeftChild(SPNodeType const &n) {
    return n == n->parent->left;
}

template<typename _Type, typename _Compare>
bool
RBTree<_Type, _Compare>::isRightChild(SPNodeType const &n) {
    return n == n->parent->right;
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase1(SPNodeType const &n) {
    if (n->parent != sentinel_)
    {
        deleteCase2(n);
    }
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase2(SPNodeType const &n) {
    auto s = sibling(n);
    if (s->color == Color::RED)
    {
        n->parent->color = Color::RED;
        s->color = Color::BLACK;
        if (isLeftChild(n))
        {
            rotateLeft(n->parent);
        }
        else
        {
            rotateRight(n->parent);
        }
    }
    deleteCase3(n);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase3(SPNodeType const &n) {
    auto s = sibling(n);
    if (n->parent->color == Color::BLACK
        && s->color == Color::BLACK
        && s->left->color == Color::BLACK
        && s->right->color == Color::BLACK)
    {
        s->color = Color::RED;
        deleteCase1(n->parent);
    }
    else
    {
        deleteCase4(n);
    }
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase4(SPNodeType const &n) {
    auto s = sibling(n);
    if (n->parent->color == Color::RED
        && s->color == Color::BLACK
        && s->left->color == Color::BLACK
        && s->right->color == Color::BLACK)
    {
        s->color = Color::RED;
        n->parent->color = Color::BLACK;
    }
    else
    {
        deleteCase5(n);
    }
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase5(SPNodeType const &n) {
    auto s = sibling(n);
    if (s->color == Color::BLACK)
    {
        if (isLeftChild(n)
            && s->right->color == Color::BLACK
            && s->left->color == Color::RED)
        {
            s->color = Color::RED;
            s->left->color = Color::BLACK;
            rotateRight(s);
        }
        else if (isRightChild(n)
                 && s->left->color == Color::BLACK
                 && s->right->color == Color::RED)
        {
            s->color = Color::RED;
            s->right->color = Color::BLACK;
            rotateLeft(s);
        }
    }
    deleteCase6(n);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase6(SPNodeType const &n) {
    auto s = sibling(n);
    s->color = n->parent->color;
    n->parent->color = Color::BLACK;

    if (isLeftChild(n))
    {
        s->right->color = Color::BLACK;
        rotateLeft(n->parent);
    }
    else
    {
        s->left->color = Color::BLACK;
        rotateRight(n->parent);
    }
}
