/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * tree node synopsis
 *
 * // for normal binary tree
 * template<typename _Type>
 * class TreeNode
 * {
 * protected:
 *  using SPNodeType = std::shared_ptr<TreeNode>;
 *  using ValueType = _Type;
 *
 * public:
 *  TreeNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
 *      :value_(v), left_(l), right_(r) {}
 *
 *  ValueType value() {
 *      return value_;
 *  }
 *
 *  void value(ValueType v) {
 *      value_ = v;
 *  }
 *
 *  SPNodeType left() {
 *      return left_;
 *  }
 *
 *  void left(SPNodeType l) {
 *      left_ = l;
 *  }
 *
 *  SPNodeType right() {
 *      return right_;
 *  }
 *
 *  void right(SPNodeType r) {
 *      right_ = r;
 *  }
 *
 * private:
 *  ValueType value_;
 *  SPNodeType left_;
 *  SPNodeType right_;
 * };
 *
 * // for derivative binary tree (e.g., avl tree, splay tree)
 * template<typename _Type, class _Derivative>
 * class __BaseTreeNode
 * {
 * protected:
 *  using SPNodeType = std::shared_ptr<_Derivative>;
 *  using ValueType = _Type;
 *
 * public:
 *  __BaseTreeNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
 *      :value_(v), left_(l), right_(r) {}
 *
 *  ValueType value() {
 *      return value_;
 *  }
 *
 *  void value(ValueType v) {
 *      value_ = v;
 *  }
 *
 *  SPNodeType left() {
 *      return left_;
 *  }
 *
 *  void left(SPNodeType l) {
 *      left_ = l;
 *  }
 *
 *  SPNodeType right() {
 *      return right_;
 *  }
 *
 *  void right(SPNodeType r) {
 *      right_ = r;
 *  }
 *
 * private:
 *  ValueType value_;
 *  SPNodeType left_;
 *  SPNodeType right_;
 * };
 *
 * template<typename _Type>
 * class DerivativeTreeNode :public __BaseTreeNode<_Type, DerivativeTreeNode<_Type>>
 * {
 * private:
 *  using BaseNode = __BaseTreeNode<_Type, DerivativeTreeNode<_Type>>;
 *  using SPNodeType = typename BaseNode::SPNodeType;
 *  using ValueType = typename BaseNode::ValueType;
 *
 * public:
 *  DerivativeTreeNode(_Type v, SPNodeType l = nullptr, SPNodeType r = nullptr)
 *      :__BaseTreeNode<_Type, DerivativeTreeNode<_Type>>(v, l, r) {}
 * };
 */

#include <memory>

#ifndef TREE_NODE_POLICY
#define TREE_NODE_POLICY

template<typename _Type>
class TreeNode
{
protected:
    using SPNodeType = std::shared_ptr<TreeNode>;
    using ValueType = _Type;

public:
    TreeNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
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

private:
    ValueType value_;
    SPNodeType left_;
    SPNodeType right_;
};

template<typename _Type, class _Derivative>
class __BaseTreeNode
{
protected:
    using SPNodeType = std::shared_ptr<_Derivative>;
    using ValueType = _Type;

public:
    __BaseTreeNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
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

private:
    ValueType value_;
    SPNodeType left_;
    SPNodeType right_;
};

template<typename _Type>
class DerivativeTreeNode : public __BaseTreeNode<_Type, DerivativeTreeNode<_Type>>
{
private:
    using BaseNode = __BaseTreeNode<_Type, DerivativeTreeNode<_Type>>;
    using SPNodeType = typename BaseNode::SPNodeType;
    using ValueType = typename BaseNode::ValueType;

public:
    DerivativeTreeNode(_Type v, SPNodeType l = nullptr, SPNodeType r = nullptr)
        : __BaseTreeNode<_Type, DerivativeTreeNode<_Type>>(v, l, r)
    {
    }
};

#endif // TREE_NODE_POLICY
