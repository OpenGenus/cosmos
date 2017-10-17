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

    tree_type *splay(tree_type *n);

    void rotateLeft(tree_type *n);

    void rotateRight(tree_type *n);

    void replace(tree_type *u, tree_type *v);

    size_t height(tree_type *n) const;

    tree_type *minimum(tree_type *n) const;

    tree_type *maximum(tree_type *n) const;

    void inorder_travel(std::ostream &output, tree_type *n);

    void preorder_travel(std::ostream &output, tree_type *n);

public:
    splay_tree() :_root(nullptr), _sz(0) {};

    size_type insert(const_reference value);

    size_type erase(const_reference value) ;

    tree_type *find(const_reference value);

    value_type minimum() const;

    value_type maximum() const ;

    size_type height() const;

    size_type size() const;

    bool empty() const ;

    void inorder_travel(std::ostream &output);

    void preorder_travel(std::ostream &output);
};
*/

#include <iostream>

// for test
// #include <fstream>
// std::fstream input, ans;

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

    tree_type *splay(tree_type *n) {
        while (n && n->parent) {
            if (!n->parent->parent) {           // zig step
                if (n->parent->left == n) {
                    rotateRight(n->parent);
                } else {
                    rotateLeft(n->parent);
                }
            } else if (n->parent->left == n && n->parent->parent->left == n->parent) {
                rotateRight(n->parent->parent);
                rotateRight(n->parent);
            } else if (n->parent->right == n && n->parent->parent->right == n->parent) {
                rotateLeft(n->parent->parent);
                rotateLeft(n->parent);
            } else if (n->parent->right == n && n->parent->parent->left == n->parent) {
                rotateLeft(n->parent);
                rotateRight(n->parent);
            } else {
                rotateRight(n->parent);
                rotateLeft(n->parent);
            }
        }

        return n;
    }

    void rotateLeft(tree_type *n) {
        tree_type *right = n->right;
        if (right != nullptr) {
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

    void rotateRight(tree_type *n) {
        tree_type *left = n->left;
        if (left != nullptr) {
            n->left = left->right;
            if (left->right != nullptr)
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

    void replace(tree_type *u, tree_type *v) {
        if (!u->parent) {
            _root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v)
            v->parent = u->parent;
    }

    size_t height(tree_type *n) const {
        if (n) {
            return 1 + max(height(_root->left), height(_root->right));
        } else {
            return 0;
        }
    }

    tree_type *minimum(tree_type *n) const {
        if (empty())
            return nullptr;
        while (n->left)
            n = n->left;

        return n;
    }

    tree_type *maximum(tree_type *n) const {
        if (empty())
            return nullptr;
        while (n->right)
            n = n->right;

        return n;
    }

    void inorder_travel(std::ostream &output, tree_type *n) {
        if (n) {
            inorder_travel(output, n->left);
            output << n->value << " ";
            inorder_travel(output, n->right);
        }
    }

    void preorder_travel(std::ostream &output, tree_type *n) {
        if (n) {
            output << n->value << " ";
            preorder_travel(output, n->left);
            preorder_travel(output, n->right);
        }
    }

public:
    splay_tree() :_root(nullptr), _sz(0) {};

    size_type insert(const_reference value) {
        tree_type *n = _root, *parent = nullptr;
        while (n) {
            parent = n;
            if (_Comp()(n->value, value)) {
                n = n->right;
            } else if (_Comp()(value, n->value)) {
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
        } else if (_Comp()(parent->value, n->value)) {
            parent->right = n;
        } else {
            parent->left = n;
        }
        splay(n);
        ++_sz;

        return 1;
    }

    size_type erase(const_reference value) {
        tree_type *n = find(value);
        if (n != nullptr) {
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

    tree_type *find(const_reference value) {
        tree_type *n = _root;
        while (n) {
            if (_Comp()(n->value, value)) {
                n = n->right;
            } else if (_Comp()(value, n->value)) {
                n = n->left;
            } else {
                return n;
            }
        }

        return nullptr;
    }

    value_type minimum() const {
        tree_type *n = minimum(_root);

        return n ? n->value : value_type{};
    }

    value_type maximum() const {
        tree_type *n = maximum(_root);

        return n ? n->value : value_type{};
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

    void inorder_travel(std::ostream &output) {
        inorder_travel(output, _root);
    }

    void preorder_travel(std::ostream &output) {
        preorder_travel(output, _root);
    }
};

// for test
// int main() {
// using namespace std;
//
// splay_tree<int> *st = new splay_tree<int>();
//
// input.open("/input.txt");
// ans.open("/ans.txt", ios::out | ios::trunc);
//
// int r, ty;
// while (input >> r) {
// input >> ty;
// cout << r << " " << ty << endl;
// if (ty == 0) {
// st->insert(r);
// } else if (ty == 1) {
// st->erase(r);
// } else {
// st->find(r);
// }
// st->preorder_travel(ans);
// st->inorder_travel(ans);
// ans << endl;
// }
//
// return 0;
// }
