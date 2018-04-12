#include <iostream>
#include <memory>
#include <cassert>
#include <string>
#include <stack>
using namespace std;

template<typename _Type, class _Derivative>
class BaseNode
{
protected:
    using ValueType = _Type;
    using SPNodeType = std::shared_ptr<_Derivative>;

public:
    BaseNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
        : value_(v), left_(l), right_(r)
    {
    }

    ValueType value()
    {
        return value_;
    }

    void value(ValueType v)
    {
        value_ = v;
    }

    SPNodeType &left()
    {
        return left_;
    }

    void left(SPNodeType l)
    {
        left_ = l;
    }

    SPNodeType &right()
    {
        return right_;
    }

    void right(SPNodeType r)
    {
        right_ = r;
    }

protected:
    ValueType value_;
    SPNodeType left_, right_;
};

template<typename _Type>
class RBNode : public BaseNode<_Type, RBNode<_Type>>
{
private:
    using ValueType = _Type;
    using SPNodeType = std::shared_ptr<RBNode>;
    using WPNodeType = std::weak_ptr<RBNode>;

public:
    enum class Color
    {
        RED,
        BLACK
    };

    RBNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr, SPNodeType p = nullptr)
        : BaseNode<_Type, RBNode<_Type>>(v, l, r), parent_(p), color_(Color::RED)
    {
    }

    SPNodeType parent()
    {
        return parent_.lock();
    }

    void parent(SPNodeType p)
    {
        parent_ = p;
    }

    Color color()
    {
        return color_;
    }

    void color(Color c)
    {
        color_ = c;
    }

private:
    WPNodeType parent_;
    Color color_;
};

struct RBTreeTest;
template<typename _Type, typename _Compare = std::less<_Type>>
class RBTree
{
private:
    typedef RBNode<_Type> NodeType;
    typedef std::shared_ptr<NodeType> SPNodeType;
    typedef typename RBNode<_Type>::Color Color;

public:
    RBTree() : root_(nullptr), sentinel_(std::make_shared<NodeType>(0)), compare_(_Compare())
    {
        sentinel_->left(sentinel_);
        sentinel_->right(sentinel_);
        sentinel_->parent(sentinel_);
        sentinel_->color(Color::BLACK);
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

    SPNodeType _find(_Type const &value);

    void rotateLeft(SPNodeType const &);

    void rotateRight(SPNodeType const &);

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

// for test
    friend RBTreeTest;
};

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::insert(_Type const &value)
{
    SPNodeType pt = std::make_shared<NodeType>(value, sentinel_, sentinel_);

    root_ = insert(root_, pt);

    fixViolation(pt);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::erase(_Type const &value)
{
    SPNodeType delete_node = _find(value);

    if (delete_node != sentinel_)
    {
        if (delete_node->left() == sentinel_)
            deleteOneNode(delete_node);
        else
        {
            SPNodeType smallest = successor(delete_node);
            auto temp = delete_node->value();
            delete_node->value(smallest->value());
            smallest->value(temp);
            deleteOneNode(smallest);
        }
    }
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteOneNode(SPNodeType &pt)
{
    auto child = pt->left() != sentinel_ ? pt->left() : pt->right();
    if (pt->parent() == sentinel_)
    {
        root_ = child;
        root_->parent(sentinel_);
        root_->color(Color::BLACK);
    }
    else
    {
        if (isLeftChild(pt))
            pt->parent()->left(child);
        else
            pt->parent()->right(child);
        child->parent(pt->parent());
        if (pt->color() == Color::BLACK)
        {
            if (child->color() == Color::RED)
                child->color(Color::BLACK);
            else
                deleteCase1(child);
        }
    }
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::find(_Type const &value)->SPNodeType const
{
    auto pt = _find(value);

    return pt != sentinel_ ? pt : nullptr;
}

template<typename _Type, typename _Compare>
std::string
RBTree<_Type, _Compare>::preOrder() const
{
    if (root_ == sentinel_)
    {
        return {};
    }
    std::string elem{};
    std::stack<SPNodeType> st{};
    st.push(root_);
    elem.append(std::to_string(st.top()->value()));
    while (!st.empty())
    {
        while (st.top()->left() != sentinel_)
        {
            elem.append(std::to_string(st.top()->left()->value()));
            st.push(st.top()->left());
        }
        while (!st.empty() && st.top()->right() == sentinel_)
            st.pop();
        if (!st.empty())
        {
            elem.append(std::to_string(st.top()->right()->value()));
            auto temp = st.top();
            st.pop();
            st.push(temp->right());
        }
    }

    return elem;
}

template<typename _Type, typename _Compare>
std::string
RBTree<_Type, _Compare>::inOrder() const
{
    if (root_ == sentinel_)
    {
        return {};
    }
    std::string elem{};
    std::stack<SPNodeType> st{};
    st.push(root_);
    while (!st.empty())
    {
        while (st.top()->left() != sentinel_)
            st.push(st.top()->left());
        while (!st.empty() && st.top()->right() == sentinel_)
        {
            elem.append(std::to_string(st.top()->value()));
            st.pop();
        }
        if (!st.empty())
        {
            elem.append(std::to_string(st.top()->value()));
            auto temp = st.top();
            st.pop();
            st.push(temp->right());
        }
    }

    return elem;
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::insert(SPNodeType &root, SPNodeType &pt)->SPNodeType &
{
    // If the tree is empty, return a new node
    if (root == sentinel_)
    {
        pt->parent(root->parent());

        return pt;
    }

    // Otherwise, recur down the tree
    if (compare_(pt->value(), root->value()))
    {
        root->left(insert(root->left(), pt));
        root->left()->parent(root);
    }
    else if (compare_(root->value(), pt->value()))
    {
        root->right(insert(root->right(), pt));
        root->right()->parent(root);
    }
    else
    {
        pt->parent(root->parent());
        pt->left(root->left());
        pt->right(root->right());
        pt->color(root->color());
    }

    // return the (unchanged) node pointer
    return root;
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::_find(_Type const &value)->SPNodeType
{
    auto pt = std::make_shared<NodeType>(value);
    std::stack<SPNodeType> st{};
    st.push(root_);
    while (!st.empty())
    {
        if (compare_(st.top()->value(), pt->value()) == compare_(pt->value(), st.top()->value()))
            return st.top();
        while (st.top()->left() != sentinel_)
        {
            st.push(st.top()->left());
            if (compare_(st.top()->value(),
                         pt->value()) == compare_(pt->value(), st.top()->value()))
                return st.top();
        }
        while (!st.empty() && st.top()->right() == sentinel_)
            st.pop();
        if (!st.empty())
        {
            if (compare_(st.top()->value(),
                         pt->value()) == compare_(pt->value(), st.top()->value()))
                return st.top();
            else
            {
                SPNodeType &temp = st.top();
                st.pop();
                st.push(temp->right());
            }
        }
    }

    return sentinel_;
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::rotateLeft(SPNodeType const &pt)
{
    auto pt_right = pt->right();

    pt->right() = pt_right->left();

    if (pt->right() != sentinel_)
        pt->right()->parent(pt);

    pt_right->parent(pt->parent());

    if (pt->parent() == sentinel_)
        root_ = pt_right;
    else if (pt == pt->parent()->left())
        pt->parent()->left(pt_right);
    else
        pt->parent()->right(pt_right);

    pt_right->left(pt);
    pt->parent(pt_right);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::rotateRight(SPNodeType const &pt)
{
    auto pt_left = pt->left();

    pt->left(pt_left->right());

    if (pt->left() != sentinel_)
        pt->left()->parent(pt);

    pt_left->parent(pt->parent());

    if (pt->parent() == sentinel_)
        root_ = pt_left;
    else if (pt == pt->parent()->left())
        pt->parent()->left(pt_left);
    else
        pt->parent()->right(pt_left);

    pt_left->right(pt);
    pt->parent(pt_left);
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::successor(SPNodeType const &pt)->SPNodeType
{
    auto child = sentinel_;
    if (pt->left() != sentinel_)
    {
        child = pt->left();
        while (child->right() != sentinel_)
            child = child->right();
    }
    else if (pt->right() != sentinel_)
    {
        child = pt->right();
        while (child->left() != sentinel_)
            child = child->left();
    }

    return child;
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::fixViolation(SPNodeType &pt)
{
    auto parent_pt = sentinel_;
    auto grand_parent_pt = sentinel_;

    while (pt->color() == Color::RED && pt->parent()->color() == Color::RED)
    {
        parent_pt = pt->parent();
        grand_parent_pt = pt->parent()->parent();

        /*
         * Case : A
         * Parent of pt is left child of Grand-parent of pt
         */
        if (parent_pt == grand_parent_pt->left())
        {
            auto uncle_pt = grand_parent_pt->right();

            /*
             * Case : 1
             * The uncle of pt is also red
             * Only Recoloring required
             */
            if (uncle_pt->color() == Color::RED)
            {
                grand_parent_pt->color(Color::RED);
                parent_pt->color(Color::BLACK);
                uncle_pt->color(Color::BLACK);
                pt = grand_parent_pt;
            }
            else
            {
                /*
                 * Case : 2
                 * pt is right child of its parent
                 * Left-rotation required
                 */
                if (pt == parent_pt->right())
                {
                    rotateLeft(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent();
                }

                /*
                 * Case : 3
                 * pt is left child of its parent
                 * Right-rotation required
                 */
                rotateRight(grand_parent_pt);
                auto temp = parent_pt->color();
                parent_pt->color(grand_parent_pt->color());
                grand_parent_pt->color(temp);
                pt = parent_pt;
            }
        }
        /*
         * Case : B
         * Parent of pt is right child of Grand-parent of pt
         */
        else
        {
            auto uncle_pt = grand_parent_pt->left();

            /*
             * Case : 1
             * The uncle of pt is also red
             * Only Recoloring required
             */
            if (uncle_pt->color() == Color::RED)
            {
                grand_parent_pt->color(Color::RED);
                parent_pt->color(Color::BLACK);
                uncle_pt->color(Color::BLACK);
                pt = grand_parent_pt;
            }
            else
            {
                /*
                 * Case : 2
                 * pt is left child of its parent
                 * Right-rotation required
                 */
                if (pt == parent_pt->left())
                {
                    rotateRight(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent();
                }

                /*
                 * Case : 3
                 * pt is right child of its parent
                 * Left-rotation required
                 */
                rotateLeft(grand_parent_pt);
                auto temp = parent_pt->color();
                parent_pt->color(grand_parent_pt->color());
                grand_parent_pt->color(temp);
                pt = parent_pt;
            }
        }
    }

    root_->color(Color::BLACK);
}

template<typename _Type, typename _Compare>
auto
RBTree<_Type, _Compare>::sibling(SPNodeType const &n)->SPNodeType &
{
    return n->parent()->left() != n ? n->parent()->left() : n->parent()->right();
}

template<typename _Type, typename _Compare>
bool
RBTree<_Type, _Compare>::isLeftChild(SPNodeType const &n)
{
    return n == n->parent()->left();
}

template<typename _Type, typename _Compare>
bool
RBTree<_Type, _Compare>::isRightChild(SPNodeType const &n)
{
    return n == n->parent()->right();
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase1(SPNodeType const &n)
{
    if (n->parent() != sentinel_)
        deleteCase2(n);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase2(SPNodeType const &n)
{
    auto s = sibling(n);
    if (s->color() == Color::RED)
    {
        n->parent()->color(Color::RED);
        s->color(Color::BLACK);
        if (isLeftChild(n))
            rotateLeft(n->parent());
        else
            rotateRight(n->parent());
    }
    deleteCase3(n);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase3(SPNodeType const &n)
{
    auto s = sibling(n);
    if (n->parent()->color() == Color::BLACK
        && s->color() == Color::BLACK
        && s->left()->color() == Color::BLACK
        && s->right()->color() == Color::BLACK)
    {
        s->color(Color::RED);
        deleteCase1(n->parent());
    }
    else
        deleteCase4(n);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase4(SPNodeType const &n)
{
    auto s = sibling(n);
    if (n->parent()->color() == Color::RED
        && s->color() == Color::BLACK
        && s->left()->color() == Color::BLACK
        && s->right()->color() == Color::BLACK)
    {
        s->color(Color::RED);
        n->parent()->color(Color::BLACK);
    }
    else
        deleteCase5(n);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase5(SPNodeType const &n)
{
    auto s = sibling(n);
    if (s->color() == Color::BLACK)
    {
        if (isLeftChild(n)
            && s->right()->color() == Color::BLACK
            && s->left()->color() == Color::RED)
        {
            s->color(Color::RED);
            s->left()->color(Color::BLACK);
            rotateRight(s);
        }
        else if (isRightChild(n)
                 && s->left()->color() == Color::BLACK
                 && s->right()->color() == Color::RED)
        {
            s->color(Color::RED);
            s->right()->color(Color::BLACK);
            rotateLeft(s);
        }
    }
    deleteCase6(n);
}

template<typename _Type, typename _Compare>
void
RBTree<_Type, _Compare>::deleteCase6(SPNodeType const &n)
{
    auto s = sibling(n);
    s->color(n->parent()->color());
    n->parent()->color(Color::BLACK);

    if (isLeftChild(n))
    {
        s->right()->color(Color::BLACK);
        rotateLeft(n->parent());
    }
    else
    {
        s->left()->color(Color::BLACK);
        rotateRight(n->parent());
    }
}
