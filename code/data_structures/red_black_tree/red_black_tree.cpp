#include <iostream>
#include <memory>
#include <cassert>
#include <string>
#include <stack>
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
struct RBNode :Node<_Tp, RBNode<_Tp> >
{
    enum class Color {RED, BLACK};
    typedef std::shared_ptr<RBNode> p_node_type;
    p_node_type parent;
    Color color;
    RBNode(_Tp d, p_node_type l = nullptr, p_node_type r = nullptr, p_node_type p = nullptr)
        :Node<_Tp, RBNode<_Tp> >(d, l, r), parent(p), color(Color::RED) {}
};

// Class to represent Red-Black Tree
template<typename _Tp, typename _Comp = std::less<_Tp> >
class RBTree
{
private:
    typedef RBNode<_Tp> node_type;
    typedef std::shared_ptr<node_type> p_node_type;
    typedef typename RBNode<_Tp>::Color Color;

public:
    // Constructor
    RBTree() :root_(nullptr), sentinel_(std::make_shared<node_type>(0)), comp_(_Comp()) {
        sentinel_->left = sentinel_;
        sentinel_->right = sentinel_;
        sentinel_->parent = sentinel_;
        sentinel_->color = Color::BLACK;
        root_ = sentinel_;
    }

    void insert(_Tp const &n);

    void erase(_Tp const &n);

    p_node_type const find(_Tp const &);

    std::string preOrder() const;

    std::string inOrder() const;

private:
    p_node_type root_;
    p_node_type sentinel_;
    _Comp comp_;

    p_node_type &insert(p_node_type &root, p_node_type &pt);

    p_node_type &_find(_Tp const &data);

    void rotateLeft(p_node_type &);

    void rotateRight(p_node_type &);

    void fixViolation(p_node_type &);

    p_node_type successor(p_node_type const &);

    p_node_type &sibling(p_node_type const &);

    bool isLeftChild(p_node_type const &);

    bool isRightChild(p_node_type const &);

    void deleteOneNode(p_node_type &);

    void deleteCase1(p_node_type const &);

    void deleteCase2(p_node_type const &);

    void deleteCase3(p_node_type const &);

    void deleteCase4(p_node_type const &);

    void deleteCase5(p_node_type const &);

    void deleteCase6(p_node_type const &);
};

// Function to insert a new node with given data
template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::insert(_Tp const &data)
{
    RBTree::p_node_type pt = std::make_shared<RBTree::node_type>(data, sentinel_, sentinel_);

    // Do a normal BST insert
    root_ = insert(root_, pt);

    // fix Red Black Tree violations
    fixViolation(pt);
}

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::erase(_Tp const &data) {
    RBTree::p_node_type delete_node = _find(data);

    // found
    if (delete_node != sentinel_)
    {
        // only root
        if (delete_node->left == sentinel_)
            deleteOneNode(delete_node);
        else
        {
            p_node_type smallest = successor(delete_node);
            swap(delete_node->data, smallest->data);
            deleteOneNode(smallest);
        }
    }
}

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::deleteOneNode(p_node_type &pt) {
    p_node_type child = pt->left != sentinel_ ? pt->left : pt->right;
    if (pt->parent == sentinel_)
    {
        root_ = child;
        root_->parent = sentinel_;
        root_->color = Color::BLACK;
    }
    else
    {
        if (isLeftChild(pt))
            pt->parent->left = child;
        else
            pt->parent->right = child;
        child->parent = pt->parent;
        if (pt->color == Color::BLACK)
        {
            if (child->color == Color::RED)
                child->color = Color::BLACK;
            else
                deleteCase1(child);
        }
    }
}

template<typename _Tp, typename _Comp>
typename RBTree<_Tp, _Comp>::p_node_type const
RBTree<_Tp, _Comp>::find(_Tp const &data) {
    auto pt = _find(data);

    return pt != sentinel_ ? pt : nullptr;
}

template<typename _Tp, typename _Comp>
std::string
RBTree<_Tp, _Comp>::preOrder() const {
    if (root_ == sentinel_)
        return {};
    std::string elem{};
    std::stack<p_node_type> st{};
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

template<typename _Tp, typename _Comp>
std::string
RBTree<_Tp, _Comp>::inOrder() const {
    if (root_ == sentinel_)
        return {};
    std::string elem{};
    std::stack<p_node_type> st{};
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

template<typename _Tp, typename _Comp>
typename RBTree<_Tp, _Comp>::p_node_type &
RBTree<_Tp, _Comp>::insert(p_node_type & root, p_node_type & pt)
{
    /* If the tree is empty, return a new node */
    if (root == sentinel_)
    {
        pt->parent = root->parent;

        return pt;
    }

    /* Otherwise, recur down the tree */
    if (comp_(pt->data, root->data))
    {
        root->left = insert(root->left, pt);
        root->left->parent = root;
    }
    else if (comp_(root->data, pt->data))
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

template<typename _Tp, typename _Comp>
typename RBTree<_Tp, _Comp>::p_node_type &
RBTree<_Tp, _Comp>::_find(_Tp const & data)
{
    p_node_type pt = std::make_shared<RBTree::node_type>(data);
    std::stack<p_node_type> st{};
    st.push(root_);
    while (!st.empty())
    {
        if (comp_(st.top()->data, pt->data) == comp_(pt->data, st.top()->data))
            return st.top();
        while (st.top()->left != sentinel_)
        {
            st.push(st.top()->left);
            if (comp_(st.top()->data, pt->data) == comp_(pt->data, st.top()->data))
                return st.top();
        }
        while (!st.empty() && st.top()->right == sentinel_)
            st.pop();
        if (!st.empty())
        {
            if (comp_(st.top()->data, pt->data) == comp_(pt->data, st.top()->data))
                return st.top();
            else
            {
                p_node_type &temp = st.top();
                st.pop();
                st.push(temp->right);
            }
        }
    }

    return sentinel_;
}

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::rotateLeft(RBTree::p_node_type &pt)
{
    RBTree::p_node_type pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != sentinel_)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == sentinel_)
        root_ = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::rotateRight(RBTree::p_node_type &pt)
{
    RBTree::p_node_type pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != sentinel_)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == sentinel_)
        root_ = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

template<typename _Tp, typename _Comp>
typename RBTree<_Tp, _Comp>::p_node_type
RBTree<_Tp, _Comp>::successor(p_node_type const &pt) {
    p_node_type child = sentinel_;
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
template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::fixViolation(RBTree::p_node_type &pt)
{
    RBTree::p_node_type parent_pt = sentinel_;
    RBTree::p_node_type grand_parent_pt = sentinel_;

    while (pt->color == Color::RED && pt->parent->color == Color::RED)
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
            RBTree::p_node_type uncle_pt = grand_parent_pt->left;

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

template<typename _Tp, typename _Comp>
typename RBTree<_Tp, _Comp>::p_node_type &
RBTree<_Tp, _Comp>::sibling(p_node_type const & n) {
    return n->parent->left != n ? n->parent->left : n->parent->right;
}

template<typename _Tp, typename _Comp>
bool
RBTree<_Tp, _Comp>::isLeftChild(p_node_type const &n) {
    return n == n->parent->left;
}

template<typename _Tp, typename _Comp>
bool
RBTree<_Tp, _Comp>::isRightChild(p_node_type const &n) {
    return n == n->parent->right;
}

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::deleteCase1(p_node_type const &n) {
    if (n->parent != sentinel_)
        deleteCase2(n);
}

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::deleteCase2(p_node_type const &n) {
    auto s = sibling(n);
    if (s->color == Color::RED)
    {
        n->parent->color = Color::RED;
        s->color = Color::BLACK;
        if (isLeftChild(n))
            rotateLeft(n->parent);
        else
            rotateRight(n->parent);
    }
    deleteCase3(n);
}

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::deleteCase3(p_node_type const &n) {
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
        deleteCase4(n);
}

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::deleteCase4(p_node_type const &n) {
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
        deleteCase5(n);
}

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::deleteCase5(p_node_type const &n) {
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

template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::deleteCase6(p_node_type const &n) {
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
