/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * splay tree synopsis
 *
 * template<typename _Type, class _Derivative>
 * class Node
 * {
 * protected:
 *  using SPNodeType = std::shared_ptr<_Derivative>;
 *  using ValueType = _Type;
 *
 * public:
 *  Node(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr);
 *
 *  ValueType value();
 *
 *  void value(ValueType v);
 *
 *  SPNodeType left();
 *
 *  void left(SPNodeType l);
 *
 *  SPNodeType right();
 *
 *  void right(SPNodeType r);
 *
 * protected:
 *  ValueType value_;
 *  std::shared_ptr<_Derivative> left_, right_;
 * };
 *
 * template<typename _Type>
 * class DerivativeNode :public Node<_Type, DerivativeNode<_Type>>
 * {
 * private:
 *  using BaseNode = Node<_Type, DerivativeNode<_Type>>;
 *  using SPNodeType = typename BaseNode::SPNodeType;
 *  using WPNodeType = std::weak_ptr<DerivativeNode>;
 *  using ValueType = typename BaseNode::ValueType;
 *
 * public:
 *  DerivativeNode(ValueType v,
 *                 SPNodeType l = nullptr,
 *                 SPNodeType r = nullptr,
 *                 WPNodeType p = WPNodeType());
 *
 *  SPNodeType parent();
 *
 *  void parent(SPNodeType p);
 *
 * private:
 *  WPNodeType parent_;
 * };
 *
 * template<typename _Type,
 *       typename _Compare = std::less<_Type>,
 *       class NodeType = DerivativeNode<_Type>>
 * class SplayTree
 * {
 * private:
 *  using SPNodeType = std::shared_ptr<NodeType>;
 *
 * public:
 *  using ValueType = _Type;
 *  using Reference = ValueType &;
 *  using ConstReference = ValueType const &;
 *  using SizeType = size_t;
 *  using DifferenceType = std::ptrdiff_t;
 *
 *  SplayTree() :root_(nullptr), size_(0), compare_(_Compare())
 *
 *  SizeType insert(ConstReference value);
 *
 *  SizeType erase(ConstReference value);
 *
 *  SPNodeType find(ConstReference value);
 *
 *  SPNodeType minimum() const;
 *
 *  SPNodeType maximum() const;
 *
 *  SizeType height() const;
 *
 *  SizeType size() const;
 *
 *  bool empty() const;
 *
 *  void inorderTravel(std::ostream &output) const;
 *
 *  void preorderTravel(std::ostream &output) const;
 *
 * private:
 *  SPNodeType root_;
 *  SizeType size_;
 *  _Compare compare_;
 *
 *  SPNodeType splay(SPNodeType n);
 *
 *  void leftRotate(SPNodeType n);
 *
 *  void rightRotate(SPNodeType n);
 *
 *  void replace(SPNodeType old, SPNodeType new_);
 *
 *  SPNodeType get(ConstReference value);
 *
 *  SizeType height(SPNodeType n) const;
 *
 *  SPNodeType minimum(SPNodeType n) const;
 *
 *  SPNodeType maximum(SPNodeType n) const;
 *
 *  void inorderTravel(std::ostream &output, SPNodeType n) const;
 *
 *  void preorderTravel(std::ostream &output, SPNodeType n) const;
 * };
 */

#include <functional>
#include <algorithm>
#include <memory>
#include <cstddef>

template<typename _Type, class _Derivative>
class Node
{
protected:
    using SPNodeType = std::shared_ptr<_Derivative>;
    using ValueType = _Type;

public:
    Node(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
        : value_(v), left_(l), right_(r)
    {
    };

    ValueType value()
    {
        return value_;
    }

    void value(ValueType v)
    {
        value_ = v;
    }

    SPNodeType left()
    {
        return left_;
    }

    void left(SPNodeType l)
    {
        left_ = l;
    }

    SPNodeType right()
    {
        return right_;
    }

    void right(SPNodeType r)
    {
        right_ = r;
    }

protected:
    ValueType value_;
    std::shared_ptr<_Derivative> left_, right_;
};

template<typename _Type>
class DerivativeNode : public Node<_Type, DerivativeNode<_Type>>
{
private:
    using BaseNode = Node<_Type, DerivativeNode<_Type>>;
    using SPNodeType = typename BaseNode::SPNodeType;
    using WPNodeType = std::weak_ptr<DerivativeNode>;
    using ValueType = typename BaseNode::ValueType;

public:
    DerivativeNode(ValueType v,
                   SPNodeType l = nullptr,
                   SPNodeType r = nullptr,
                   WPNodeType p = WPNodeType())
        : BaseNode(v, l, r), parent_(p)
    {
    };

    SPNodeType parent()
    {
        return parent_.lock();
    }

    void parent(SPNodeType p)
    {
        parent_ = p;
    }

private:
    WPNodeType parent_;
};

template<typename _Type,
         typename _Compare = std::less<_Type>,
         class NodeType = DerivativeNode<_Type>>
class SplayTree
{
private:
    using SPNodeType = std::shared_ptr<NodeType>;

public:
    using ValueType = _Type;
    using Reference = ValueType &;
    using ConstReference = ValueType const &;
    using SizeType = size_t;
    using DifferenceType = std::ptrdiff_t;

    SplayTree() : root_(nullptr), size_(0), compare_(_Compare())
    {
        ;
    }

    SizeType insert(ConstReference value)
    {
        SPNodeType n = root_, parent = nullptr;
        while (n)
        {
            parent = n;
            if (compare_(n->value(), value))
                n = n->right();
            else if (compare_(value, n->value()))
                n = n->left();
            else
            {
                n->value(value);

                return 0;
            }
        }
        n = std::make_shared<NodeType>(value);
        n->parent(parent);

        if (parent == nullptr)
            root_ = n;
        else if (compare_(parent->value(), n->value()))
            parent->right(n);
        else
            parent->left(n);
        splay(n);
        ++size_;

        return 1;
    }

    SizeType erase(ConstReference value)
    {
        SPNodeType n = get(value);
        if (n)
        {
            splay(n);
            if (n->left() == nullptr)
                replace(n, n->right());
            else if (n->right() == nullptr)
                replace(n, n->left());
            else
            {
                SPNodeType min = minimum(n->right());
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

    SPNodeType find(ConstReference value)
    {
        return get(value);
    }

    SPNodeType minimum() const
    {
        return minimum(root_);
    }

    SPNodeType maximum() const
    {
        return maximum(root_);
    }

    SizeType height() const
    {
        return height(root_);
    }

    SizeType size() const
    {
        return size_;
    }

    bool empty() const
    {
        return size_ == 0;
    }

    void inorderTravel(std::ostream &output) const
    {
        inorderTravel(output, root_);
    }

    void preorderTravel(std::ostream &output) const
    {
        preorderTravel(output, root_);
    }

private:
    SPNodeType root_;
    SizeType size_;
    _Compare compare_;

    SPNodeType splay(SPNodeType n)
    {
        while (n && n->parent())
        {
            if (!n->parent()->parent())             // zig step
            {
                if (n->parent()->left() == n)
                    rightRotate(n->parent());
                else
                    leftRotate(n->parent());
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

    void leftRotate(SPNodeType n)
    {
        SPNodeType right = n->right();
        if (right)
        {
            n->right(right->left());
            if (right->left())
                right->left()->parent(n);
            right->parent(n->parent());
        }

        if (n->parent() == nullptr)
            root_ = right;
        else if (n == n->parent()->left())
            n->parent()->left(right);
        else
            n->parent()->right(right);

        if (right)
            right->left(n);
        n->parent(right);
    }

    void rightRotate(SPNodeType n)
    {
        SPNodeType left = n->left();
        if (left)
        {
            n->left(left->right());
            if (left->right())
                left->right()->parent(n);
            left->parent(n->parent());
        }

        if (n->parent() == nullptr)
            root_ = left;
        else if (n == n->parent()->left())
            n->parent()->left(left);
        else
            n->parent()->right(left);
        if (left)
            left->right(n);
        n->parent(left);
    }

    void replace(SPNodeType old, SPNodeType new_)
    {
        if (old->parent() == nullptr)
            root_ = new_;
        else if (old == old->parent()->left())
            old->parent()->left(new_);
        else
            old->parent()->right(new_);
        if (new_)
            new_->parent(old->parent());
    }

    SPNodeType get(ConstReference value)
    {
        SPNodeType n = root_;
        while (n)
        {
            if (compare_(n->value(), value))
                n = n->right();
            else if (compare_(value, n->value()))
                n = n->left();
            else
            {
                splay(n);

                return n;
            }
        }

        return nullptr;
    }

    SizeType height(SPNodeType n) const
    {
        if (n)
            return 1 + std::max(height(n->left()), height(n->right()));
        else
            return 0;
    }

    SPNodeType minimum(SPNodeType n) const
    {
        if (n)
            while (n->left())
                n = n->left();

        return n;
    }

    SPNodeType maximum(SPNodeType n) const
    {
        if (n)
            while (n->right())
                n = n->right();

        return n;
    }

    void inorderTravel(std::ostream &output, SPNodeType n) const
    {
        if (n)
        {
            inorderTravel(output, n->left());
            output << n->value() << " ";
            inorderTravel(output, n->right());
        }
    }

    void preorderTravel(std::ostream &output, SPNodeType n) const
    {
        if (n)
        {
            output << n->value() << " ";
            preorderTravel(output, n->left());
            preorderTravel(output, n->right());
        }
    }
};

/*
 * // for test
 #include <iostream>
 #include <fstream>
 * std::fstream input, ans;
 * int main() {
 *  using namespace std;
 *
 *  std::shared_ptr<SplayTree<int>> st = std::make_shared<SplayTree<int>>();
 *
 *  input.open("/sample.txt");
 *  ans.open("/output.txt", ios::out | ios::trunc);
 *
 *  int r, ty;
 *  while (input >> r)
 *  {
 *      input >> ty;
 *
 *      // cout << r << " " << ty << endl;
 *      if (ty == 0)
 *      {
 *          st->insert(r);
 *      }
 *      else if (ty == 1)
 *      {
 *          st->erase(r);
 *      }
 *      else
 *      {
 *          st->find(r);
 *      }
 *
 *      st->preorderTravel(ans);
 *      st->inorderTravel(ans);
 *      ans << endl;
 *  }
 *  ans << st->find(0);
 *  ans << st->height();
 *  ans << st->minimum();
 *  ans << st->maximum();
 *  ans << st->size();
 *  ans << st->empty();
 *
 *  return 0;
 * }
 * // */
