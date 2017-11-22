/*
    Part of Cosmos by OpenGenus Foundation

    diameter of tree synopsis

template<typename _TreeNode>
size_t
diameter(_TreeNode node);

template<typename _TreeNode>
size_t
diameterRecursive(_TreeNode node, size_t &maximum);
 */

#include <algorithm>
#include <memory>
#include <stack>
#include "../tree_node/tree_node.cpp"

template<typename _TreeNode>
size_t
diameter(_TreeNode node)
{
    size_t res{};
    diameterRecursive(node, res);

    return res;
}

template<typename _TreeNode>
size_t
diameterRecursive(_TreeNode node, size_t &maximum)
{
    if (node != nullptr)
    {
        size_t leftMax{}, rightMax{};

        // DFS
        size_t leftHeight = diameterRecursive(node->left(), leftMax);
        size_t rightHeight = diameterRecursive(node->right(), rightMax);

        maximum = leftHeight + rightHeight + 1;
        maximum = std::max(maximum, leftMax);
        maximum = std::max(maximum, rightMax);

        return std::max(leftHeight, rightHeight) + 1;
    }

    return 0;
}