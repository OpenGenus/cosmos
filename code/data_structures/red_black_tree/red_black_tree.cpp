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

class RBTreeTest;

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

    p_node_type &successor(p_node_type &);

    p_node_type &sibling(p_node_type &);

    bool isLeftChild(p_node_type &);

    bool isRightChild(p_node_type &);

    void deleteCase1(p_node_type &);

    void deleteCase2(p_node_type &);

    void deleteCase3(p_node_type &);

    void deleteCase4(p_node_type &);

    void deleteCase5(p_node_type &);

    void deleteCase6(p_node_type &);

    friend RBTreeTest;
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

template<typename _Tp, typename _Comp>
typename RBTree<_Tp, _Comp>::p_node_type &
RBTree<_Tp, _Comp>::successor(p_node_type & pt) {
    p_node_type child = sentinel_;
    if (pt->left != sentinel_)
    {
        child = pt->left;
        while (child->right != sentinel_)
            child = child->right;
        swap(pt->data, child->data);
    }
    else if (pt->right != sentinel_)
    {
        child = pt->right;
        while (child->left != sentinel_)
            child = child->left;
        swap(pt->data, child->data);
    }

    return sentinel_;
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
RBTree<_Tp, _Comp>::sibling(p_node_type & n) {
    return n->parent->left != n ? n->parent->left : n->parent->right;
}

template<typename _Tp, typename _Comp>
bool
RBTree<_Tp, _Comp>::isLeftChild(p_node_type &n) {
    return n == n->parent->left;
}

template<typename _Tp, typename _Comp>
bool
RBTree<_Tp, _Comp>::isRightChild(p_node_type &n) {
    return n == n->parent->right;
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

// test of RBTree methods
struct RBTreeTest
{
    typedef RBTree<int> tree_type;
    using node_type = tree_type::node_type;
    using p_node_type = tree_type::p_node_type;
    using Color = tree_type::Color;

    RBTreeTest() {
        testSibling();

        // below test of delete cases need ignore invoke
        testDeleteCase2();
        testDeleteCase3();
        testDeleteCase4();
        testDeleteCase5();
        testDeleteCase6();
    }

    void testSibling() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), l = std::make_shared<node_type>(0),
                    r = std::make_shared<node_type>(0);
        n->left = l;
        n->right = r;
        l->parent = n;
        r->parent = n;
        assert(t.sibling(l) == r);
        assert(t.sibling(r) == l);
    }

    void testDeleteCase2() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
                    s = std::make_shared<node_type>(0), sl = std::make_shared<node_type>(0),
                    sr = std::make_shared<node_type>(0);

        // test n is left of parent
        p->color = Color::BLACK;
        s->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase2(n);
        assert(p->color == Color::RED);
        assert(s->color == Color::BLACK);
        assert(s->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(sl->left == t.sentinel_);
        assert(sl->right == t.sentinel_);
        assert(sr->left == t.sentinel_);
        assert(sr->right == t.sentinel_);
        assert(s->left == p);
        assert(s->right == sr);
        assert(p->parent == s);
        assert(sr->parent == s);
        assert(p->left == n);
        assert(p->right == sl);
        assert(n->parent == p);
        assert(sl->parent == p);

        // test n is right of parent
        p->color = Color::BLACK;
        s->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = s;
        p->right = n;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase2(n);
        assert(p->color == Color::RED);
        assert(s->color == Color::BLACK);
        assert(s->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(sl->left == t.sentinel_);
        assert(sl->right == t.sentinel_);
        assert(sr->left == t.sentinel_);
        assert(sr->right == t.sentinel_);
        assert(s->left == sl);
        assert(s->right == p);
        assert(sl->parent == s);
        assert(p->parent == s);
        assert(p->left == sr);
        assert(p->right == n);
        assert(sr->parent == p);
        assert(n->parent == p);
    }

    void testDeleteCase3() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
                    s = std::make_shared<node_type>(0), sl = std::make_shared<node_type>(0),
                    sr = std::make_shared<node_type>(0);
        n->color = p->color = s->color = sl->color = sr->color = Color::BLACK;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase3(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);

        n->color = p->color = s->color = sl->color = sr->color = Color::BLACK;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = s;
        p->right = n;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase3(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
    }

    void testDeleteCase4() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
                    s = std::make_shared<node_type>(0), sl = std::make_shared<node_type>(0),
                    sr = std::make_shared<node_type>(0);
        n->color = s->color = sl->color = sr->color = Color::BLACK;
        p->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase4(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);

        n->color = s->color = sl->color = sr->color = Color::BLACK;
        p->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = s;
        p->right = n;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase4(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
    }

    void testDeleteCase5() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
                    s = std::make_shared<node_type>(0), sl = std::make_shared<node_type>(0),
                    sr = std::make_shared<node_type>(0), s_l = std::make_shared<node_type>(0),
                    s_r = std::make_shared<node_type>(0);
        n->color = p->color = s->color = sr->color = s_l->color = s_r->color = Color::BLACK;
        sl->color = Color::RED;
        p->parent = n->left = n->right = sr->left = sr->right = \
                                                        s_l->left = s_l->right = s_r->left =
                                                                                     s_r->right =
                                                                                         t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        sl->left = s_l;
        sl->right = s_r;
        s_l->parent = s_r->parent = sl;
        t.deleteCase5(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
        assert(s_l->color == Color::BLACK);
        assert(s_r->color == Color::BLACK);
        assert(p->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(sr->left == t.sentinel_);
        assert(sr->right == t.sentinel_);
        assert(s_l->left == t.sentinel_);
        assert(s_l->right == t.sentinel_);
        assert(s_r->left == t.sentinel_);
        assert(s_r->right == t.sentinel_);
        assert(p->left == n);
        assert(p->right == sl);
        assert(n->parent == p);
        assert(sl->parent == p);
        assert(sl->left == s_l);
        assert(sl->right == s);
        assert(s_l->parent == sl);
        assert(s->parent == sl);
        assert(s->left == s_r);
        assert(s->right == sr);
        assert(s_r->parent == s);
        assert(sr->parent == s);

        n->color = p->color = s->color = sl->color = s_l->color = s_r->color = Color::BLACK;
        sr->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = \
                                                        s_l->left = s_l->right = s_r->left =
                                                                                     s_r->right =
                                                                                         t.sentinel_;
        p->left = s;
        p->right = n;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        sr->left = s_l;
        sr->right = s_r;
        s_l->parent = s_r->parent = sr;
        t.deleteCase5(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
        assert(s_l->color == Color::BLACK);
        assert(s_r->color == Color::BLACK);
        assert(p->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(sl->left == t.sentinel_);
        assert(sl->right == t.sentinel_);
        assert(s_l->left == t.sentinel_);
        assert(s_l->right == t.sentinel_);
        assert(s_r->left == t.sentinel_);
        assert(s_r->right == t.sentinel_);
        assert(p->left == sr);
        assert(p->right == n);
        assert(n->parent == p);
        assert(sr->parent == p);
        assert(sr->left == s);
        assert(sr->right == s_r);
        assert(s->parent == sr);
        assert(s_r->parent == sr);
        assert(s->left == sl);
        assert(s->right == s_l);
        assert(sl->parent == s);
        assert(s_l->parent == s);
    }

    void testDeleteCase6() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
                    s = std::make_shared<node_type>(0), sc = std::make_shared<node_type>(0);
        p->color = n->color = s->color = Color::BLACK;
        sc->color = Color::RED;
        p->parent = n->left = n->right = s->left = sc->left = sc->right = t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = p;
        s->parent = p;
        s->right = sc;
        sc->parent = s;
        t.deleteCase6(n);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(s->color == Color::BLACK);
        assert(sc->color == Color::BLACK);
        assert(s->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(p->right == t.sentinel_);
        assert(sc->left == t.sentinel_);
        assert(sc->right == t.sentinel_);
        assert(s->left == p);
        assert(s->right == sc);
        assert(p->parent == s);
        assert(sc->parent == s);
        assert(p->left == n);
        assert(n->parent == p);

        p->color = n->color = s->color = Color::BLACK;
        sc->color = Color::RED;
        p->parent = n->left = n->right = s->right = sc->left = sc->right = t.sentinel_;
        p->left = s;
        p->right = n;
        s->parent = p;
        n->parent = p;
        s->left = sc;
        sc->parent = s;
        t.deleteCase6(n);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(s->color == Color::BLACK);
        assert(sc->color == Color::BLACK);
        assert(s->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(p->left == t.sentinel_);
        assert(sc->left == t.sentinel_);
        assert(sc->right == t.sentinel_);
        assert(s->left == sc);
        assert(s->right == p);
        assert(sc->parent == s);
        assert(p->parent == s);
        assert(p->right == n);
        assert(n->parent == p);
    }
};

// Driver Code
int
main()
{
    RBTreeTest t;
    test();

    return 0;
}
