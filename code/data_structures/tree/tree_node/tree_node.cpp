/*
 Part of Cosmos by OpenGenus Foundation

 tree node synopsis

// for normal binary tree
template<typename _Type>
struct TreeNode
{
    using SPNodeType = std::shared_ptr<TreeNode>;
    using ValueType = _Type;

    ValueType value_;
    SPNodeType left_;
    SPNodeType right_;
    TreeNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
        :value_(v), left_(l), right_(r) {}
};

// for derivative binary tree (e.g., avl tree, splay tree)
template<typename _Type, class _Derivative>
struct __BaseTreeNode
{
    using SPNodeType = std::shared_ptr<_Derivative>;
    using ValueType = _Type;

    ValueType value_;
    SPNodeType left_;
    SPNodeType right_;
    __BaseTreeNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
        :value_(v), left_(l), right_(r) {}
};

template<typename _Type>
struct DerivativeTreeNode :__BaseTreeNode<_Type, DerivativeTreeNode<_Type>>
{
    using SPNodeType = std::shared_ptr<DerivativeTreeNode>;
    using ValueType = _Type;

    DerivativeTreeNode(_Type v, SPNodeType l = nullptr, SPNodeType r = nullptr)
        :__BaseTreeNode<_Type, DerivativeTreeNode<_Type>>(v, l, r) {}
};
 */

#include <memory>

#ifndef TREE_NODE_POLICY
#define TREE_NODE_POLICY

template<typename _Type>
struct TreeNode
{
    using SPNodeType = std::shared_ptr<TreeNode>;
    using ValueType = _Type;

    ValueType value_;
    SPNodeType left_;
    SPNodeType right_;
    TreeNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
        :value_(v), left_(l), right_(r) {}
};

template<typename _Type, class _Derivative>
struct __BaseTreeNode
{
    using SPNodeType = std::shared_ptr<_Derivative>;
    using ValueType = _Type;

    ValueType value_;
    SPNodeType left_;
    SPNodeType right_;
    __BaseTreeNode(ValueType v, SPNodeType l = nullptr, SPNodeType r = nullptr)
        :value_(v), left_(l), right_(r) {}
};

template<typename _Type>
struct DerivativeTreeNode :__BaseTreeNode<_Type, DerivativeTreeNode<_Type>>
{
    using SPNodeType = std::shared_ptr<DerivativeTreeNode>;
    using ValueType = _Type;

    DerivativeTreeNode(_Type v, SPNodeType l = nullptr, SPNodeType r = nullptr)
        :__BaseTreeNode<_Type, DerivativeTreeNode<_Type>>(v, l, r) {}
};

#endif // TREE_NODE_POLICY
