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
        value_type value;
        std::shared_ptr<derive> left, right;
        tree(value_type v,
             std::shared_ptr<derive> l = nullptr,
             std::shared_ptr<derive> r = nullptr);
    };

    struct iter_tree :public tree<iter_tree> {
        std::shared_ptr<iter_tree> parent;
        iter_tree(value_type v,
                  std::shared_ptr<iter_tree> l = nullptr,
                  std::shared_ptr<iter_tree> r = nullptr,
                  std::shared_ptr<iter_tree> p = nullptr);
    };

    typedef struct iter_tree           tree_type;
    typedef std::shared_ptr<iter_tree> p_tree_type;

public:
    splay_tree() :_root(nullptr), _sz(0), _comp(_Comp());

    size_type insert(const_reference value);

    size_type erase(const_reference value);

    p_tree_type find(const_reference value);

    p_tree_type minimum() const;

    p_tree_type maximum() const;

    size_type height() const;

    size_type size() const;

    bool empty() const;

    void inorderTravel(std::ostream &output) const;

    void preorderTravel(std::ostream &output) const;

private:
    p_tree_type _root;
    size_type _sz;
    _Comp _comp;

    p_tree_type splay(p_tree_type n);

    void leftRotate(p_tree_type n);

    void rightRotate(p_tree_type n);

    void replace(p_tree_type old, p_tree_type new_);

    p_tree_type get(const_reference value);

    size_type height(p_tree_type n) const;

    p_tree_type minimum(p_tree_type n) const;

    p_tree_type maximum(p_tree_type n) const;

    void inorderTravel(std::ostream &output, p_tree_type n) const;

    void preorderTravel(std::ostream &output, p_tree_type n) const;
};
 */

#include <functional>
#include <algorithm>
#include <memory>

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
        value_type value;
        std::shared_ptr<derive> left, right;
        tree(value_type v, std::shared_ptr<derive> l = nullptr, std::shared_ptr<derive> r = nullptr)
            :value(v), left(l), right(r) {};
    };

    struct iter_tree :public tree<iter_tree> {
        std::shared_ptr<iter_tree> parent;
        iter_tree(value_type v,
                  std::shared_ptr<iter_tree> l = nullptr,
                  std::shared_ptr<iter_tree> r = nullptr,
                  std::shared_ptr<iter_tree> p = nullptr)
            :tree<iter_tree>(v, l, r), parent(p) {};
    };

    typedef struct iter_tree           tree_type;
    typedef std::shared_ptr<iter_tree> p_tree_type;

public:
    splay_tree() :_root(nullptr), _sz(0), _comp(_Comp()) {;}

    size_type insert(const_reference value) {
        p_tree_type n = _root, parent = nullptr;
        while (n)
        {
            parent = n;
            if (_comp(n->value, value))
            {
                n = n->right;
            }
            else if (_comp(value, n->value))
            {
                n = n->left;
            }
            else
            {
                n->value = value;

                return 0;
            }
        }
        n = std::make_shared<tree_type>(value);
        n->parent = parent;

        if (parent == nullptr)
        {
            _root = n;
        }
        else if (_comp(parent->value, n->value))
        {
            parent->right = n;
        }
        else
        {
            parent->left = n;
        }
        splay(n);
        ++_sz;

        return 1;
    }

    size_type erase(const_reference value) {
        p_tree_type n = get(value);
        if (n)
        {
            splay(n);
            if (n->left == nullptr)
            {
                replace(n, n->right);
            }
            else if (n->right == nullptr)
            {
                replace(n, n->left);
            }
            else
            {
                p_tree_type min = minimum(n->right);
                if (min->parent != n)
                {
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

    p_tree_type find(const_reference value) {
        return get(value);
    }

    p_tree_type minimum() const {
        return minimum(_root);
    }

    p_tree_type maximum() const {
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

    void inorderTravel(std::ostream &output) const {
        inorderTravel(output, _root);
    }

    void preorderTravel(std::ostream &output) const {
        preorderTravel(output, _root);
    }

private:
    p_tree_type _root;
    size_type _sz;
    _Comp _comp;

    p_tree_type splay(p_tree_type n) {
        while (n && n->parent)
        {
            if (!n->parent->parent)             // zig step
            {
                if (n->parent->left == n)
                {
                    rightRotate(n->parent);
                }
                else
                {
                    leftRotate(n->parent);
                }
            }
            else if (n->parent->left == n && n->parent->parent->left == n->parent)
            {
                rightRotate(n->parent->parent);
                rightRotate(n->parent);
            }
            else if (n->parent->right == n && n->parent->parent->right == n->parent)
            {
                leftRotate(n->parent->parent);
                leftRotate(n->parent);
            }
            else if (n->parent->right == n && n->parent->parent->left == n->parent)
            {
                leftRotate(n->parent);
                rightRotate(n->parent);
            }
            else
            {
                rightRotate(n->parent);
                leftRotate(n->parent);
            }
        }

        return n;
    }

    void leftRotate(p_tree_type n) {
        p_tree_type right = n->right;
        if (right)
        {
            n->right = right->left;
            if (right->left)
                right->left->parent = n;
            right->parent = n->parent;
        }

        if (n->parent == nullptr)
        {
            _root = right;
        }
        else if (n == n->parent->left)
        {
            n->parent->left = right;
        }
        else
        {
            n->parent->right = right;
        }

        if (right)
            right->left = n;
        n->parent = right;
    }

    void rightRotate(p_tree_type n) {
        p_tree_type left = n->left;
        if (left)
        {
            n->left = left->right;
            if (left->right)
                left->right->parent = n;
            left->parent = n->parent;
        }

        if (n->parent == nullptr)
        {
            _root = left;
        }
        else if (n == n->parent->left)
        {
            n->parent->left = left;
        }
        else
        {
            n->parent->right = left;
        }
        if (left)
            left->right = n;
        n->parent = left;
    }

    void replace(p_tree_type old, p_tree_type new_) {
        if (old->parent == nullptr)
        {
            _root = new_;
        }
        else if (old == old->parent->left)
        {
            old->parent->left = new_;
        }
        else
        {
            old->parent->right = new_;
        }
        if (new_)
            new_->parent = old->parent;
    }

    p_tree_type get(const_reference value) {
        p_tree_type n = _root;
        while (n)
        {
            if (_comp(n->value, value))
            {
                n = n->right;
            }
            else if (_comp(value, n->value))
            {
                n = n->left;
            }
            else
            {
                splay(n);

                return n;
            }
        }

        return nullptr;
    }

    size_type height(p_tree_type n) const {
        if (n)
        {
            return 1 + std::max(height(n->left), height(n->right));
        }
        else
        {
            return 0;
        }
    }

    p_tree_type minimum(p_tree_type n) const {
        if (n)
            while (n->left)
                n = n->left;

        return n;
    }

    p_tree_type maximum(p_tree_type n) const {
        if (n)
            while (n->right)
                n = n->right;

        return n;
    }

    void inorderTravel(std::ostream &output, p_tree_type n) const {
        if (n)
        {
            inorderTravel(output, n->left);
            output << n->value << " ";
            inorderTravel(output, n->right);
        }
    }

    void preorderTravel(std::ostream &output, p_tree_type n) const {
        if (n)
        {
            output << n->value << " ";
            preorderTravel(output, n->left);
            preorderTravel(output, n->right);
        }
    }
};

/*
// for test
 #include <iostream>
 #include <fstream>
std::fstream input, ans;
int main() {
    using namespace std;

    std::shared_ptr<splay_tree<int> > st = std::make_shared<splay_tree<int> >();

    input.open("/sample.txt");
    ans.open("/output.txt", ios::out | ios::trunc);

    int r, ty;
    while (input >> r)
    {
        input >> ty;

        // cout << r << " " << ty << endl;
        if (ty == 0)
        {
            st->insert(r);
        }
        else if (ty == 1)
        {
            st->erase(r);
        }
        else
        {
            st->find(r);
        }

        st->preorderTravel(ans);
        st->inorderTravel(ans);
        ans << endl;
    }
    ans << st->find(0);
    ans << st->height();
    ans << st->minimum();
    ans << st->maximum();
    ans << st->size();
    ans << st->empty();

    return 0;
}
// */
