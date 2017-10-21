/*
    Part of Cosmos by OpenGenus Foundation
    arne andersson tree synopsis

template<typename _Derive,
         typename _Tp,
         typename _Comp = std::less<_Tp> >
struct BinaryTreeNode {
    _Derive *left, *right;
    _Tp value;
    BinaryTreeNode(_Tp v, _Derive *l = nullptr, _Derive *r = nullptr)
    :value(v), left(l), right(r);
};

template<typename _Tp,
         typename _Comp = std::less<_Tp> >
struct AABinaryTreeNode :public BinaryTreeNode<AABinaryTreeNode<_Tp, _Comp>, _Tp, _Comp> {
    size_t level;
    AABinaryTreeNode(_Tp v, AABinaryTreeNode *l = nullptr, AABinaryTreeNode *r = nullptr)
    :level(1), BinaryTreeNode<AABinaryTreeNode<_Tp, _Comp>, _Tp, _Comp>(v, l, r);
};

template<typename _Tp,
         typename _Comp = std::less<_Tp>,
         typename _NodeType = BinaryTreeNode<_Tp, _Comp> >
class BinaryTree {
public:
    typedef _Tp               value_type;
    typedef value_type &      reference;
    typedef value_type const &const_reference;
    typedef ptrdiff_t         difference_type;
    typedef size_t            size_type;

protected:
    typedef BinaryTree<_Tp, _Comp, _NodeType> self;
    typedef _NodeType                         node_type;

public:
    BinaryTree(node_type *r = nullptr) :root_(r), sz_(0), comp_(_Comp()), release_(true);
 
    ~BinaryTree();

    node_type const * &maximum() const;

    node_type const * &minimum() const;

    size_type size() const;

    bool empty() const;

    void inOrder(std::ostream &output) const;

    void preOrder(std::ostream &output) const;

    void postOrder(std::ostream &output) const;

protected:
    node_type *root_;
    size_type sz_;
    _Comp comp_;
    bool release_;
    node_type *nil_;

    // post order release
    void release(node_type * &n);

    node_type *get(const_reference value);

    node_type const * &maximum(node_type const *n) const;

    node_type const * &minimum(node_type const *n) const;

    void inOrder(std::ostream &output, node_type const *n) const;

    void preOrder(std::ostream &output, node_type const *n) const;

    void postOrder(std::ostream &output, node_type const *n) const;
};
*/

#include <algorithm>
#include <stack>

template<typename _Derive,
         typename _Tp,
         typename _Comp = std::less<_Tp> >
struct BinaryTreeNode {
    _Derive *left, *right;
    _Tp value;
    BinaryTreeNode(_Tp v, _Derive *l = nullptr, _Derive *r = nullptr)
        :value(v), left(l), right(r) {};
};

template<typename _Tp,
         typename _Comp = std::less<_Tp> >
struct AABinaryTreeNode :public BinaryTreeNode<AABinaryTreeNode<_Tp, _Comp>, _Tp, _Comp> {
    size_t level;
    AABinaryTreeNode(_Tp v, AABinaryTreeNode *l = nullptr, AABinaryTreeNode *r = nullptr)
        :level(1), BinaryTreeNode<AABinaryTreeNode<_Tp, _Comp>, _Tp, _Comp>(v, l, r) {};
};

template<typename _Tp,
         typename _Comp = std::less<_Tp>,
         typename _NodeType = BinaryTreeNode<_Tp, _Comp> >
class BinaryTree {
public:
    typedef _Tp               value_type;
    typedef value_type &      reference;
    typedef value_type const &const_reference;
    typedef ptrdiff_t         difference_type;
    typedef size_t            size_type;

protected:
    typedef BinaryTree<_Tp, _Comp, _NodeType> self;
    typedef _NodeType                         node_type;

public:

    BinaryTree(node_type *r = nullptr) :root_(r), sz_(0), comp_(_Comp()), release_(true) {};

    ~BinaryTree() {
        release(root_);
    }

    node_type const * &maximum() const {
        return maximum(root_);
    }

    node_type const * &minimum() const {
        return minimum(root_);
    }

    size_type size() const {
        return sz_;
    }

    bool empty() const {
        return sz_ == 0;
    }

    void inOrder(std::ostream &output) const {
        inOrder(output, root_);
    }

    void preOrder(std::ostream &output) const {
        preOrder(output, root_);
    }

    void postOrder(std::ostream &output) const {
        postOrder(output, root_);
    }

protected:
    node_type *root_;
    size_type sz_;
    _Comp comp_;
    bool release_;
    node_type *nil_;

    // post order release
    void release(node_type * &n) {
        if (release_ == true)
        {
            std::stack<node_type *> releaseNodes{};
            do {
                while (n != nil_) {
                    releaseNodes.push(n);
                    n = n->left;
                }
                while (!releaseNodes.empty() && releaseNodes.top()->right == nil_) {
                    node_type *deleteNode = releaseNodes.top();
                    releaseNodes.pop();
                    delete deleteNode;
                }
                if (!releaseNodes.empty())
                {
                    node_type *deleteNode = releaseNodes.top();
                    node_type *right = releaseNodes.top()->right;
                    releaseNodes.pop();
                    n = right;
                    delete deleteNode;
                }
            } while (!releaseNodes.empty() || n != nil_);
        }
        release_ = false;
    }

    node_type *get(const_reference value) {
        node_type *n = root_;
        while (n != nil_) {
            if (comp_(value, n->value))
            {
                n = n->left;
            }
            else if (comp_(n->value, value))
            {
                n = n->right;
            }
            else
            {
                break;
            }
        }

        return n;
    }

    node_type const * &maximum(node_type const *n) const {
        if (n != nil_)
            while (n->right != nil_)
                n = n->right;

        return n;
    }

    node_type const * &minimum(node_type const *n) const {
        if (n != nil_)
            while (n->left != nil_)
                n = n->left;

        return n;
    }

    void inOrder(std::ostream &output, node_type const *n) const {
        if (n != nil_)
        {
            inOrder(output, n->left);
            output << n->value << " ";
            inOrder(output, n->right);
        }
    }

    void preOrder(std::ostream &output, node_type const *n) const {
        if (n != nil_)
        {
            output << n->value << " ";
            preOrder(output, n->left);
            preOrder(output, n->right);
        }
    }

    void postOrder(std::ostream &output, node_type const *n) const {
        if (n != nil_)
        {
            postOrder(output, n->left);
            output << n->value << " ";
            postOrder(output, n->right);
        }
    }
};

template<typename _Tp,
         typename _Comp = std::less<_Tp> >
class AATree :public BinaryTree<_Tp, _Comp, AABinaryTreeNode<_Tp, _Comp> > {
private:
    typedef BinaryTree<_Tp, _Comp, AABinaryTreeNode<_Tp, _Comp> > base;
    typedef AATree<_Tp, _Comp>                                    self;

public:
    using typename base::size_type;
    using typename base::value_type;
    using typename base::reference;
    using typename base::const_reference;
    using typename base::difference_type;

protected:
    using typename base::node_type;
    using base::root_;
    using base::comp_;
    using base::nil_;
    using base::sz_;

public:
    AATree() :base() {
        nil_ = new node_type(0);
        nil_->left = nil_;
        nil_->right = nil_;
        nil_->level = 0;
        root_ = nil_;
    }

    ~AATree() {
        base::release(root_);
        delete nil_;
    }

    void insert(const_reference value) {
        insert(root_, value);
    }

    void erase(const_reference value) {
        erase(root_, value);
    }

    node_type const *find(const_reference value) {
        return get(value);
    }

private:
    // implement by recursive
    void insert(node_type * &n, const_reference value) {
        if (n == nil_)
        {
            makeNode(n, value);
            ++sz_;
        }
        else
        {
            if (comp_(value, n->value))
            {
                insert(n->left, value);
            }
            else if (comp_(n->value, value))
            {
                insert(n->right, value);
            }
            else        // depend on implement
            {
                n->value = value;
            }
        }
        skew(n);
        split(n);
    }

    void erase(node_type *&n, const_reference value) {

    }

    // input: T, a node representing an AA tree that needs to be rebalanced.
    // output: Another node representing the rebalanced AA tree.
    node_type *skew(node_type *n) {
        if (n != nil_
            && n->left != nil_
            && n->left->level == n->level)
        {
            node_type *left = n->left;
            n->left = left->right;
            left->right = n;
            n = left;
        }
    }

    // input: T, a node representing an AA tree that needs to be rebalanced.
    // output: Another node representing the rebalanced AA tree
    node_type *split(node_type *n) {
        if (n != nil_
            && n->right != nil_
            && n->right->right != nil_
            && n->level == n->right->right->level)
        {
            node_type *right = n->right;
            n->right = right->left;
            right->left = n;
            n = right;
            ++n->level;
        }

        return n;
    }

    void makeNode(node_type * &n, value_type value) {
        n = new node_type(value, nil_, nil_);
    }
};

// for test
#include <iostream>
using namespace std;
int main() {
    aa_tree<int> aat;

    return 0;
}
// */
