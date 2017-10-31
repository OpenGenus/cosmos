#include <iostream>
#include <queue>
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

    void insert(const _Tp &n);

    p_node_type find(const _Tp &);

    std::string preOrder();

    std::string inOrder();

private:
    p_node_type root_;
    p_node_type sentinel_;
    _Comp comp_;

    p_node_type &insert(p_node_type &root, p_node_type &pt);

    p_node_type &_find(const _Tp &data);

    void rotateLeft(p_node_type &);

    void rotateRight(p_node_type &);

    void fixViolation(p_node_type &);
};

// Function to insert a new node with given data
template<typename _Tp, typename _Comp>
void
RBTree<_Tp, _Comp>::insert(const _Tp &data)
{
    RBTree::p_node_type pt = std::make_shared<RBTree::node_type>(data, sentinel_, sentinel_);

    // Do a normal BST insert
    root_ = insert(root_, pt);

    // fix Red Black Tree violations
    fixViolation(pt);
}

template<typename _Tp, typename _Comp>
typename RBTree<_Tp, _Comp>::p_node_type
RBTree<_Tp, _Comp>::find(const _Tp &data) {
    auto pt = _find(data);

    return pt != sentinel_ ? pt : nullptr;
}

template<typename _Tp, typename _Comp>
std::string
RBTree<_Tp, _Comp>::preOrder() {
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
RBTree<_Tp, _Comp>::inOrder() {
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

    /* return the (unchanged) node pointer */
    return root;
}

template<typename _Tp, typename _Comp>
typename RBTree<_Tp, _Comp>::p_node_type &
RBTree<_Tp, _Comp>::_find(const _Tp &data)
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
                p_node_type temp = st.top();
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

void
test() {
    std::shared_ptr<RBTree<int> > rbt;
    rbt = make_shared<RBTree<int> >();
    assert(rbt->preOrder() == "");
    assert(rbt->find(32) == nullptr);
    rbt->insert(1);
    rbt->insert(4);
    rbt->insert(7);
    rbt->insert(10);
    rbt->insert(2);
    rbt->insert(6);
    rbt->insert(8);
    rbt->insert(3);
    rbt->insert(5);
    rbt->insert(9);
    rbt->insert(100);
    assert(rbt->preOrder() == "74213659810100");
    rbt->insert(40);
    assert(rbt->preOrder() == "7421365984010100");
    rbt->insert(30);
    assert(rbt->preOrder() == "742136598401030100");
    rbt->insert(20);
    assert(rbt->preOrder() == "74213659840201030100");
    rbt->insert(15);
    assert(rbt->preOrder() == "7421365209810154030100");
    rbt->insert(50);
    assert(rbt->preOrder() == "742136520981015403010050");
    rbt->insert(60);
    assert(rbt->preOrder() == "74213652098101540306050100");
    rbt->insert(70);
    assert(rbt->preOrder() == "7421365209810154030605010070");
    rbt->insert(80);
    assert(rbt->preOrder() == "742136520981015403060508070100");
    rbt->insert(63);
    assert(rbt->preOrder() == "74213652098101560403050807063100");
    rbt->insert(67);
    assert(rbt->preOrder() == "7421365209810156040305080676370100");
    rbt->insert(65);
    rbt->insert(69);
    rbt->insert(37);
    rbt->insert(33);
    rbt->insert(35);
    rbt->insert(31);
    assert(rbt->inOrder() == "1234567891015203031333537405060636567697080100");
    assert(rbt->preOrder() == "2074213659810156040333031373550806763657069100");
    assert(rbt->find(31) != nullptr);
    assert(rbt->find(32) == nullptr);

    rbt->erase(69);
    rbt->erase(65);
    rbt->erase(1);
    rbt->erase(3);
    rbt->erase(2);
    rbt->erase(60);
    assert(rbt->inOrder() == "4567891015203031333537405063677080100");
    assert(rbt->preOrder() == "2075469810155033303137354080676370100");
    rbt->erase(35);
    rbt->erase(37);
    rbt->erase(40);
    rbt->erase(50);
    assert(rbt->inOrder() == "45678910152030313363677080100");
    assert(rbt->preOrder() == "20754698101567333130638070100");
}

// Driver Code
int
main()
{
    test();

    return 0;
}
