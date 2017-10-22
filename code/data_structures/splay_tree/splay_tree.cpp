/*
    Part of Cosmos by OpenGenus Foundation

    splay tree synopsis

template<typename _Tp, typename _Comp = std::less<_Tp> >
class splay_tree {
public:
    typedef _Tp               value_type;
    typedef value_type &      reference;
    typedef value_type const &const_reference;
    typedef size_t            size_type;
    typedef ptrdiff_t         difference_type;

private:
    template<typename derive>
    struct tree {
        derive *left, *right;
        value_type value;
        tree(value_type v, derive *l = nullptr, derive *r = nullptr);
    };

    struct iter_tree :public tree<iter_tree> {
        iter_tree *parent;
        iter_tree(value_type v,
                  iter_tree *p = nullptr,
                  iter_tree *l = nullptr,
                  iter_tree *r = nullptr);
    };

    typedef struct iter_tree tree_type;
    
    tree_type *_root;
    size_type _sz;
    _Comp _comp;

    tree_type *splay(tree_type *n);

    void left_rotate(tree_type *n);

    void right_rotate(tree_type *n);

    void replace(tree_type *old, tree_type *new_);

    tree_type *get(const_reference value);

    size_type height(tree_type *n) const;

    tree_type *minimum(tree_type *n) const;

    tree_type *maximum(tree_type *n) const;

    void inorder_travel(std::ostream &output, tree_type *n) const;

    void preorder_travel(std::ostream &output, tree_type *n) const;

public:
    splay_tree() :_root(nullptr), _sz(0), _comp(_Comp());

    ~splay_tree();

    void release(tree_type *n);

    size_type insert(const_reference value);

    size_type erase(const_reference value);

    tree_type const *find(const_reference value);
 
    tree_type const *minimum() const;

    tree_type const *maximum() const;

    size_type height() const;

    size_type size() const;

    bool empty() const;

    void inorder_travel(std::ostream &output) const;

    void preorder_travel(std::ostream &output) const;
};
*/

#include <functional>

template<typename _Tp, typename _Comp = std::less<_Tp> >
class splay_tree {
public:
    typedef _Tp               value_type;
    typedef value_type &      reference;
    typedef value_type const &const_reference;
    typedef size_t            size_type;
    typedef ptrdiff_t         difference_type;

private:
    template<typename derive>
    struct tree {
        derive *left, *right;
        value_type value;
        tree(value_type v, derive *l = nullptr, derive *r = nullptr)
            :value(v), left(l), right(r) {};
    };

    struct iter_tree :public tree<iter_tree> {
        iter_tree *parent;
        iter_tree(value_type v,
                  iter_tree *p = nullptr,
                  iter_tree *l = nullptr,
                  iter_tree *r = nullptr)
            :parent(p), tree<iter_tree>(v, l, r) {};
    };

    typedef struct iter_tree tree_type;

    tree_type *_root;
    size_type _sz;
    _Comp _comp;

    tree_type *splay(tree_type *n) {
        while (n && n->parent) {
            if (!n->parent->parent) {           // zig step
                if (n->parent->left == n) {
                    right_rotate(n->parent);
                } else {
                    left_rotate(n->parent);
                }
            } else if (n->parent->left == n && n->parent->parent->left == n->parent) {
                right_rotate(n->parent->parent);
                right_rotate(n->parent);
            } else if (n->parent->right == n && n->parent->parent->right == n->parent) {
                left_rotate(n->parent->parent);
                left_rotate(n->parent);
            } else if (n->parent->right == n && n->parent->parent->left == n->parent) {
                left_rotate(n->parent);
                right_rotate(n->parent);
            } else {
                right_rotate(n->parent);
                left_rotate(n->parent);
            }
        }

        return n;
    }

    void left_rotate(tree_type *n) {
        tree_type *right = n->right;
        if (right) {
            n->right = right->left;
            if (right->left)
                right->left->parent = n;
            right->parent = n->parent;
        }

        if (n->parent == nullptr) {
            _root = right;
        } else if (n == n->parent->left) {
            n->parent->left = right;
        } else {
            n->parent->right = right;
        }

        if (right)
            right->left = n;
        n->parent = right;
    }

    void right_rotate(tree_type *n) {
        tree_type *left = n->left;
        if (left) {
            n->left = left->right;
            if (left->right)
                left->right->parent = n;
            left->parent = n->parent;
        }

        if (n->parent == nullptr) {
            _root = left;
        } else if (n == n->parent->left) {
            n->parent->left = left;
        } else {
            n->parent->right = left;
        }
        if (left)
            left->right = n;
        n->parent = left;
    }

    void replace(tree_type *old, tree_type *new_) {
        if (old->parent == nullptr) {
            _root = new_;
        } else if (old == old->parent->left) {
            old->parent->left = new_;
        } else {
            old->parent->right = new_;
        }
        if (new_)
            new_->parent = old->parent;
    }

    tree_type *get(const_reference value) {
        tree_type *n = _root;
        while (n) {
            if (_comp(n->value, value)) {
                n = n->right;
            } else if (_comp(value, n->value)) {
                n = n->left;
            } else {
                splay(n);

                return n;
            }
        }

        return nullptr;
    }

    size_type height(tree_type *n) const {
        if (n) {
            return 1 + std::max(height(n->left), height(n->right));
        } else {
            return 0;
        }
    }

    tree_type *minimum(tree_type *n) const {
        if (n)
            while (n->left)
                n = n->left;

        return n;
    }

    tree_type *maximum(tree_type *n) const {
        if (n)
            while (n->right)
                n = n->right;

        return n;
    }

    void inorder_travel(std::ostream &output, tree_type *n) const {
        if (n) {
            inorder_travel(output, n->left);
            output << n->value << " ";
            inorder_travel(output, n->right);
        }
    }

    void preorder_travel(std::ostream &output, tree_type *n) const {
        if (n) {
            output << n->value << " ";
            preorder_travel(output, n->left);
            preorder_travel(output, n->right);
        }
    }

public:
    splay_tree() :_root(nullptr), _sz(0), _comp(_Comp()) {;}

    ~splay_tree() {release(_root);}

    void release(tree_type *n) {
        if (n) {
            release(n->left);
            release(n->right);
            delete n;
        }
    }

    size_type insert(const_reference value) {
        tree_type *n = _root, *parent = nullptr;
        while (n) {
            parent = n;
            if (_comp(n->value, value)) {
                n = n->right;
            } else if (_comp(value, n->value)) {
                n = n->left;
            } else {
                n->value = value;

                return 0;
            }
        }
        n = new tree_type(value);
        n->parent = parent;

        if (parent == nullptr) {
            _root = n;
        } else if (_comp(parent->value, n->value)) {
            parent->right = n;
        } else {
            parent->left = n;
        }
        splay(n);
        ++_sz;

        return 1;
    }

    size_type erase(const_reference value) {
        tree_type *n = get(value);
        if (n) {
            splay(n);
            if (n->left == nullptr) {
                replace(n, n->right);
            } else if (n->right == nullptr) {
                replace(n, n->left);
            } else {
                tree_type *min = minimum(n->right);
                if (min->parent != n) {
                    replace(min, min->right);
                    min->right = n->right;
                    min->right->parent = min;
                }
                replace(n, min);
                min->left = n->left;
                min->left->parent = min;
            }
            --_sz;

            return 1;
        }

        return 0;
    }

    tree_type const *find(const_reference value) {
        return get(value);
    }

    tree_type const *minimum() const {
        return minimum(_root);
    }

    tree_type const *maximum() const {
        return maximum(_root);
    }

    size_type height() const {
        return height(_root);
    }

    size_type size() const {
        return _sz;
    }

    bool empty() const {
        return _sz == 0;
    }

    void inorder_travel(std::ostream &output) const {
        inorder_travel(output, _root);
    }

    void preorder_travel(std::ostream &output) const {
        preorder_travel(output, _root);
    }
};

/*
// for test
#include <iostream>
#include <fstream>
std::fstream input, ans;
int main() {
    using namespace std;

    splay_tree<int> *st = new splay_tree<int>();

    input.open("/sample.txt");
    ans.open("/output.txt", ios::out | ios::trunc);

    int r, ty;
    while (input >> r) {
        input >> ty;

// cout << r << " " << ty << endl;
        if (ty == 0) {
            st->insert(r);
        } else if (ty == 1) {
            st->erase(r);
        } else {
            st->find(r);
        }

        st->preorder_travel(ans);
        st->inorder_travel(ans);
        ans << endl;
    }
    ans << st->find(0);
    ans << st->height();
    ans << st->minimum();
    ans << st->maximum();
    ans << st->size();
    ans << st->empty();

    delete st;

    return 0;
}

// */
