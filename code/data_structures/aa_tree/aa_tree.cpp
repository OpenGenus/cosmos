/*
    Part of Cosmos by OpenGenus Foundation
    arne andersson tree synopsis

template<typename _Derive, typename _Tp, typename _Comp = std::less<_Tp> >
struct binary_tree_node {
    _Derive *left, *right;
    _Tp value;
    binary_tree_node(_Tp v, _Derive *l = nullptr, _Derive *r = nullptr) :value(v), left(l), right(r);
};

template<typename _Tp, typename _Comp = std::less<_Tp> >
struct aa_binary_tree_node :public binary_tree_node<aa_binary_tree_node<_Tp, _Comp>, _Tp, _Comp> {
    size_t level;
    aa_binary_tree_node(_Tp v, aa_binary_tree_node *l = nullptr, aa_binary_tree_node *r = nullptr)
        :level(1), binary_tree_node<aa_binary_tree_node<_Tp, _Comp>, _Tp, _Comp>(v, l, r);
};

template<typename _Tp,
         typename _Comp = std::less<_Tp>,
         typename _NodeType = binary_tree_node<_Tp, _Comp> >
class binary_tree {
protected:
    typedef binary_tree<_Tp, _Comp, _NodeType> self;
    typedef _NodeType                          node_type;

public:
    typedef _Tp               value_type;
    typedef value_type &      reference;
    typedef value_type const &const_reference;
    typedef ptrdiff_t         difference_type;
    typedef size_t            size_type;

    binary_tree(node_type *r = nullptr) :_root(r), _sz(0), _comp(_Comp());
    ~binary_tree();

    node_type const *&maximum() const;

    node_type const *&minimum() const;

    size_type size() const;

    bool empty() const;

    void in_order(std::ostream &output) const;

    void pre_order(std::ostream &output) const;

    void post_order(std::ostream &output) const;

protected:
    node_type *_root;
    size_type _sz;
    _Comp _comp;

    void release(node_type *&n);

    node_type *get(const_reference value);

    node_type const *&maximum(node_type const *n) const;

    node_type const *&minimum(node_type const *n) const;

    void in_order(std::ostream &output, node_type const *n) const;

    void pre_order(std::ostream &output, node_type const *n) const;

    void post_order(std::ostream &output, node_type const *n) const;
};
*/

#include <algorithm>
#include <stack>

template<typename _Derive, typename _Tp, typename _Comp = std::less<_Tp> >
struct binary_tree_node {
    _Derive *left, *right;
    _Tp value;
    binary_tree_node(_Tp v, _Derive *l = nullptr, _Derive *r = nullptr)
        :value(v), left(l), right(r) {};
};

template<typename _Tp, typename _Comp = std::less<_Tp> >
struct aa_binary_tree_node :public binary_tree_node<aa_binary_tree_node<_Tp, _Comp>, _Tp, _Comp> {
    size_t level;
    aa_binary_tree_node(_Tp v, aa_binary_tree_node *l = nullptr, aa_binary_tree_node *r = nullptr)
        :level(1), binary_tree_node<aa_binary_tree_node<_Tp, _Comp>, _Tp, _Comp>(v, l, r) {};
};

template<typename _Tp, typename _Comp = std::less<_Tp>, typename _NodeType = binary_tree_node<_Tp,
                                                                                              _Comp> >
class binary_tree {
protected:
    typedef binary_tree<_Tp, _Comp, _NodeType> self;
    typedef _NodeType                          node_type;

public:
    typedef _Tp               value_type;
    typedef value_type &      reference;
    typedef value_type const &const_reference;
    typedef ptrdiff_t         difference_type;
    typedef size_t            size_type;

    binary_tree(node_type *r = nullptr) :_root(r), _sz(0), _comp(_Comp()) {};
    ~binary_tree() {
        release(_root);
    }

    node_type const *&maximum() const {
        return maximum(_root);
    }

    node_type const *&minimum() const {
        return minimum(_root);
    }

    size_type size() const {
        return _sz;
    }

    bool empty() const {
        return _sz == 0;
    }

    void in_order(std::ostream &output) const {
        in_order(output, _root);
    }

    void pre_order(std::ostream &output) const {
        pre_order(output, _root);
    }

    void post_order(std::ostream &output) const {
        post_order(output, _root);
    }

protected:
    node_type *_root;
    size_type _sz;
    _Comp _comp;

    // post order release
    void release(node_type *&n) {
        if (n != nullptr) {
            std::stack<node_type *> release_nodes{};
            do {
                while (n != nullptr) {
                    release_nodes.push(n);
                    n = n->left;
                }
                while (!release_nodes.empty() && release_nodes.top()->right == nullptr) {
                    node_type *delete_node = release_nodes.top();
                    release_nodes.pop();
                    delete delete_node;
                }
                if (!release_nodes.empty()) {
                    node_type *delete_node = release_nodes.top();
                    node_type *right = release_nodes.top()->right;
                    release_nodes.pop();
                    n = right;
                    delete delete_node;
                }
            } while (!release_nodes.empty() || n != nullptr);
        }
    }

    node_type *get(const_reference value) {
        node_type *n = _root;
        while (n != nullptr) {
            if (_comp(value, n->value)) {
                n = n->left;
            } else if (_comp(n->value, value)) {
                n = n->right;
            } else {
                break;
            }
        }

        return n;
    }

    node_type const *&maximum(node_type const *n) const {
        if (n != nullptr)
            while (n->right != nullptr)
                n = n->right;

        return n;
    }

    node_type const *&minimum(node_type const *n) const {
        if (n != nullptr)
            while (n->left != nullptr)
                n = n->left;

        return n;
    }

    void in_order(std::ostream &output, node_type const *n) const {
        if (n != nullptr) {
            in_order(output, n->left);
            output << n->value << " ";
            in_order(output, n->right);
        }
    }

    void pre_order(std::ostream &output, node_type const *n) const {
        if (n != nullptr) {
            output << n->value << " ";
            pre_order(output, n->left);
            pre_order(output, n->right);
        }
    }

    void post_order(std::ostream &output, node_type const *n) const {
        if (n != nullptr) {
            post_order(output, n->left);
            output << n->value << " ";
            post_order(output, n->right);
        }
    }
};

template<typename _Tp, typename _Comp = std::less<_Tp> >
class aa_tree :public binary_tree<_Tp, _Comp, aa_binary_tree_node<_Tp, _Comp> > {
protected:
    typedef binary_tree<_Tp, _Comp, aa_binary_tree_node<_Tp, _Comp> > base;
    typedef aa_tree<_Tp, _Comp>                                       self;
    using typename base::node_type;
    using base::_root;

public:
    using typename base::size_type;
    using typename base::value_type;
    using typename base::reference;
    using typename base::const_reference;
    using typename base::difference_type;

    aa_tree() :base() {;}

    void insert(const_reference value) {
        insert(_root, value);
    }

    void erase(const_reference value) {
        erase(_root, value);
    }

    node_type const *find(const_reference value) {
        return get(value);
    }

private:
    // implement by recursive
    void insert(node_type *&n, const_reference value) {
        if (n == nullptr)
            n = new node_type(value);
        else {
            if (_comp(value, n->value)) {
                insert(n->left, value);
            } else if (_comp(n->value, value)) {
                insert(n->right, value);
            } else {    //depend on implement
                n->value = value;
            }
        }
        skew(n);
        split(n);
    }

    void erase(node_type *&n, const_reference value) {

    }

    //input: T, a node representing an AA tree that needs to be rebalanced.
    //output: Another node representing the rebalanced AA tree.
    void skew(node_type *&n) {
        if (n != nullptr
            && n->left != nullptr
            && n->left->level == n->level) {
            node_type *left = n->left;
            n->left = left->right;
            left->right = n;
            n = left;
        }
    }

    //input: T, a node representing an AA tree that needs to be rebalanced.
    //output: Another node representing the rebalanced AA tree
    void split(node_type *&n) {
        if (n != nullptr
            && n->right != nullptr
            && n->right->right != nullptr
            && n->level == n->right->right->level) {
            node_type * right = n->right;
            n->right = right->left;
            right->left = n;
            n = right;
            ++n->level;
        }
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
