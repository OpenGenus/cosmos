/*
 Part of Cosmos by OpenGenus Foundation

 tree node synopsis

// for normal binary tree
template<typename _Tp>
struct TreeNode
{
    _Tp val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    TreeNode(_Tp v,
             std::shared_ptr<TreeNode> l = nullptr,
             std::shared_ptr<TreeNode> r = nullptr);
};

// for derivative binary tree (e.g., avl tree, splay tree)
template<typename _Tp, class _Derivative>
struct __BaseTreeNode
{
    _Tp val;
    std::shared_ptr<_Derivative> left;
    std::shared_ptr<_Derivative> right;
    __BaseTreeNode(_Tp v,
                   std::shared_ptr<_Derivative> l = nullptr,
                   std::shared_ptr<_Derivative> r = nullptr);
};

template<typename _Tp>
struct DerivativeTreeNode :__BaseTreeNode<_Tp, DerivativeTreeNode<_Tp> >
{
    DerivativeTreeNode(_Tp v,
                       std::shared_ptr<DerivativeTreeNode> l = nullptr,
                       std::shared_ptr<DerivativeTreeNode> r = nullptr);
};
 */

#include <memory>

#ifndef TREE_NODE_POLICY
#define TREE_NODE_POLICY

template<typename _Tp>
struct TreeNode
{
    _Tp val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    TreeNode(_Tp v,
             std::shared_ptr<TreeNode> l = nullptr,
             std::shared_ptr<TreeNode> r = nullptr)
        :val(v), left(l), right(r) {}
};

template<typename _Tp, class _Derivative>
struct __BaseTreeNode
{
    _Tp val;
    std::shared_ptr<_Derivative> left;
    std::shared_ptr<_Derivative> right;
    __BaseTreeNode(_Tp v,
                   std::shared_ptr<_Derivative> l = nullptr,
                   std::shared_ptr<_Derivative> r = nullptr)
        :val(v), left(l), right(r) {}
};

template<typename _Tp>
struct DerivativeTreeNode :__BaseTreeNode<_Tp, DerivativeTreeNode<_Tp>>
{
    DerivativeTreeNode(_Tp v,
                       std::shared_ptr<DerivativeTreeNode> l = nullptr,
                       std::shared_ptr<DerivativeTreeNode> r = nullptr)
        :__BaseTreeNode<_Tp, DerivativeTreeNode<_Tp>>(v, l, r) {}
};

#endif // TREE_NODE_POLICY
