/*
 Part of Cosmos by OpenGenus Foundation

 splay tree synopsis

template<typename _Tp, typename _Compare = std::less<_Tp> >
class splay_tree {
public:
    using value_type = _Tp;
    using reference = value_type &;
    using const_reference = value_type const&;
    using SizeType = size_t;
    using difference_type = ptrdiff_t;

private:
    template<typename _Derivative>
    class Node
    {
    public:
        Node(value_type v,
             std::shared_ptr<_Derivative> l = nullptr,
             std::shared_ptr<_Derivative> r = nullptr);

        value_type value();

        void value(value_type v);

        std::shared_ptr<_Derivative> left();

        void left(std::shared_ptr<_Derivative> l);

        std::shared_ptr<_Derivative> right();

        void right(std::shared_ptr<_Derivative> r);

    private:
        value_type value_;
        std::shared_ptr<_Derivative> left_, right_;
    };

    class DerivativeNode :public Node<DerivativeNode>
    {
    public:
        DerivativeNode(value_type v,
                       std::shared_ptr<DerivativeNode> l = nullptr,
                       std::shared_ptr<DerivativeNode> r = nullptr,
                       std::shared_ptr<DerivativeNode> p = nullptr);

        std::shared_ptr<DerivativeNode> parent();

        void parent(std::shared_ptr<DerivativeNode> p);

    private:
        std::shared_ptr<DerivativeNode> parent_;
    };
    using NodeType = struct DerivativeNode;
    using PSNodeType = std::shared_ptr<DerivativeNode>;

public:
    splay_tree() :root_(nullptr), size_(0), compare_(_Compare());

    SizeType insert(const_reference value);

    SizeType erase(const_reference value);

    PSNodeType find(const_reference value);

    PSNodeType minimum() const;

    PSNodeType maximum() const;

    SizeType height() const;

    SizeType size() const;

    bool empty() const;

    void inorderTravel(std::ostream &output) const;

    void preorderTravel(std::ostream &output) const;

private:
    PSNodeType root_;
    SizeType size_;
    _Compare compare_;

    PSNodeType splay(PSNodeType n);

    void leftRotate(PSNodeType n);

    void rightRotate(PSNodeType n);

    void replace(PSNodeType old, PSNodeType new_);

    PSNodeType get(const_reference value);

    SizeType height(PSNodeType n) const;

    PSNodeType minimum(PSNodeType n) const;

    PSNodeType maximum(PSNodeType n) const;

    void inorderTravel(std::ostream &output, PSNodeType n) const;

    void preorderTravel(std::ostream &output, PSNodeType n) const;
};
 */

#include <functional>
#include <algorithm>
#include <memory>

template<typename _Type, typename _Compare = std::less<_Type>>
class splay_tree
{
public:
    using value_type = _Type;
    using reference = value_type &;
    using const_reference = value_type const &;
    using SizeType = size_t;
    using difference_type = ptrdiff_t;

private:
    template<typename _Derivative>
    class Node
    {
    public:
        Node(value_type v,
             std::shared_ptr<_Derivative> l = nullptr,
             std::shared_ptr<_Derivative> r = nullptr)
            :value_(v), left_(l), right_(r) {};

        value_type value() {
            return value_;
        }

        void value(value_type v) {
            value_ = v;
        }

        std::shared_ptr<_Derivative> left() {
            return left_;
        }

        void left(std::shared_ptr<_Derivative> l) {
            left_ = l;
        }

        std::shared_ptr<_Derivative> right() {
            return right_;
        }

        void right(std::shared_ptr<_Derivative> r) {
            right_ = r;
        }

    private:
        value_type value_;
        std::shared_ptr<_Derivative> left_, right_;
    };

    class DerivativeNode :public Node<DerivativeNode>
    {
    public:
        DerivativeNode(value_type v,
                       std::shared_ptr<DerivativeNode> l = nullptr,
                       std::shared_ptr<DerivativeNode> r = nullptr,
                       std::shared_ptr<DerivativeNode> p = nullptr)
            :Node<DerivativeNode>(v, l, r), parent_(p) {};

        std::shared_ptr<DerivativeNode> parent() {
            return parent_;
        }

        void parent(std::shared_ptr<DerivativeNode> p) {
            parent_ = p;
        }

    private:
        std::shared_ptr<DerivativeNode> parent_;
    };

    using NodeType = struct DerivativeNode;
    using PSNodeType = std::shared_ptr<DerivativeNode>;

public:
    splay_tree() :root_(nullptr), size_(0), compare_(_Compare()) {;}

    SizeType insert(const_reference value) {
        PSNodeType n = root_, parent = nullptr;
        while (n)
        {
            parent = n;
            if (compare_(n->value(), value))
            {
                n = n->right();
            }
            else if (compare_(value, n->value()))
            {
                n = n->left();
            }
            else
            {
                n->value(value);

                return 0;
            }
        }
        n = std::make_shared<NodeType>(value);
        n->parent(parent);

        if (parent == nullptr)
        {
            root_ = n;
        }
        else if (compare_(parent->value(), n->value()))
        {
            parent->right(n);
        }
        else
        {
            parent->left(n);
        }
        splay(n);
        ++size_;

        return 1;
    }

    SizeType erase(const_reference value) {
        PSNodeType n = get(value);
        if (n)
        {
            splay(n);
            if (n->left() == nullptr)
            {
                replace(n, n->right());
            }
            else if (n->right() == nullptr)
            {
                replace(n, n->left());
            }
            else
            {
                PSNodeType min = minimum(n->right());
                if (min->parent() != n)
                {
                    replace(min, min->right());
                    min->right(n->right());
                    min->right()->parent(min);
                }
                replace(n, min);
                min->left(n->left());
                min->left()->parent(min);
            }
            --size_;

            return 1;
        }

        return 0;
    }

    PSNodeType find(const_reference value) {
        return get(value);
    }

    PSNodeType minimum() const {
        return minimum(root_);
    }

    PSNodeType maximum() const {
        return maximum(root_);
    }

    SizeType height() const {
        return height(root_);
    }

    SizeType size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void inorderTravel(std::ostream &output) const {
        inorderTravel(output, root_);
    }

    void preorderTravel(std::ostream &output) const {
        preorderTravel(output, root_);
    }

private:
    PSNodeType root_;
    SizeType size_;
    _Compare compare_;

    PSNodeType splay(PSNodeType n) {
        while (n && n->parent())
        {
            if (!n->parent()->parent())             // zig step
            {
                if (n->parent()->left() == n)
                {
                    rightRotate(n->parent());
                }
                else
                {
                    leftRotate(n->parent());
                }
            }
            else if (n->parent()->left() == n && n->parent()->parent()->left() == n->parent())
            {
                rightRotate(n->parent()->parent());
                rightRotate(n->parent());
            }
            else if (n->parent()->right() == n && n->parent()->parent()->right() == n->parent())
            {
                leftRotate(n->parent()->parent());
                leftRotate(n->parent());
            }
            else if (n->parent()->right() == n && n->parent()->parent()->left() == n->parent())
            {
                leftRotate(n->parent());
                rightRotate(n->parent());
            }
            else
            {
                rightRotate(n->parent());
                leftRotate(n->parent());
            }
        }

        return n;
    }

    void leftRotate(PSNodeType n) {
        PSNodeType right = n->right();
        if (right)
        {
            n->right(right->left());
            if (right->left())
            {
                right->left()->parent(n);
            }
            right->parent(n->parent());
        }

        if (n->parent() == nullptr)
        {
            root_ = right;
        }
        else if (n == n->parent()->left())
        {
            n->parent()->left(right);
        }
        else
        {
            n->parent()->right(right);
        }

        if (right)
        {
            right->left(n);
        }
        n->parent(right);
    }

    void rightRotate(PSNodeType n) {
        PSNodeType left = n->left();
        if (left)
        {
            n->left(left->right());
            if (left->right())
            {
                left->right()->parent(n);
            }
            left->parent(n->parent());
        }

        if (n->parent() == nullptr)
        {
            root_ = left;
        }
        else if (n == n->parent()->left())
        {
            n->parent()->left(left);
        }
        else
        {
            n->parent()->right(left);
        }
        if (left)
        {
            left->right(n);
        }
        n->parent(left);
    }

    void replace(PSNodeType old, PSNodeType new_) {
        if (old->parent() == nullptr)
        {
            root_ = new_;
        }
        else if (old == old->parent()->left())
        {
            old->parent()->left(new_);
        }
        else
        {
            old->parent()->right(new_);
        }
        if (new_)
        {
            new_->parent(old->parent());
        }
    }

    PSNodeType get(const_reference value) {
        PSNodeType n = root_;
        while (n)
        {
            if (compare_(n->value(), value))
            {
                n = n->right();
            }
            else if (compare_(value, n->value()))
            {
                n = n->left();
            }
            else
            {
                splay(n);

                return n;
            }
        }

        return nullptr;
    }

    SizeType height(PSNodeType n) const {
        if (n)
        {
            return 1 + std::max(height(n->left()), height(n->right()));
        }
        else
        {
            return 0;
        }
    }

    PSNodeType minimum(PSNodeType n) const {
        if (n)
        {
            while (n->left())
                n = n->left();
        }

        return n;
    }

    PSNodeType maximum(PSNodeType n) const {
        if (n)
        {
            while (n->right())
                n = n->right();
        }

        return n;
    }

    void inorderTravel(std::ostream &output, PSNodeType n) const {
        if (n)
        {
            inorderTravel(output, n->left());
            output << n->value() << " ";
            inorderTravel(output, n->right());
        }
    }

    void preorderTravel(std::ostream &output, PSNodeType n) const {
        if (n)
        {
            output << n->value() << " ";
            preorderTravel(output, n->left());
            preorderTravel(output, n->right());
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

    std::shared_ptr<splay_tree<int>> st = std::make_shared<splay_tree<int>>();

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
