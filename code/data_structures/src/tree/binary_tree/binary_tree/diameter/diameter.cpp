/*
 *  Part of Cosmos by OpenGenus Foundation
 *
 *  diameter of tree synopsis
 *
 * template<typename _TreeNode>
 * size_t
 * diameter(_TreeNode node);
 *
 * template<typename _TreeNode>
 * void
 * diameterIterative(_TreeNode const &node, size_t &maximum);
 *
 * template<typename _TreeNode>
 * size_t
 * getDiameter(_TreeNode const &node);
 *
 * template<typename _TreeNode>
 * size_t
 * getDeep(_TreeNode const &node);
 *
 * template<typename _TreeNode>
 * size_t
 * diameterRecursive(_TreeNode node, size_t &maximum);
 */

#include <algorithm>
#include <memory>
#include <stack>
#include "../node/node.cpp"

template<typename _TreeNode>
size_t
diameter(_TreeNode node)
{
    size_t res{};
    diameterIterative(node, res);

    return res;
}

template<typename _TreeNode>
void
diameterIterative(_TreeNode const &node, size_t &maximum)
{
    maximum = 0;
    if (node != nullptr)
    {
        std::stack<_TreeNode> diameters;
        diameters.push(node);

        // DFS
        while (!diameters.empty())
        {
            while (diameters.top()->left() != nullptr)
                diameters.push(diameters.top()->left());
            while (!diameters.empty()
                   && (diameters.top() == nullptr
                       || diameters.top()->right() == nullptr))
            {
                if (diameters.top() == nullptr) // if back from right hand
                    diameters.pop();
                auto top = diameters.top();
                maximum = std::max(maximum, static_cast<size_t>(getDiameter(top)));
                top->value(static_cast<int>(getDeep(top)));
                diameters.pop();
            }
            if (!diameters.empty())
            {
                auto right = diameters.top()->right();
                diameters.push(nullptr);    // prevent visit two times when return to parent
                diameters.push(right);
            }
        }
    }
}

template<typename _TreeNode>
size_t
getDiameter(_TreeNode const &node)
{
    size_t res = 1;
    res += node->left() ? node->left()->value() : 0;
    res += node->right() ? node->right()->value() : 0;

    return res;
}

template<typename _TreeNode>
size_t
getDeep(_TreeNode const &node)
{
    size_t res = 1;
    res += std::max(node->left() ? node->left()->value() : 0,
                    node->right() ? node->right()->value() : 0);

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
