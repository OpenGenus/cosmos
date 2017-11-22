/*
    Part of Cosmos by OpenGenus Foundation

    diameter of tree synopsis

template<typename _TreeNode>
size_t diameter_impl(_TreeNode *node, size_t &max);

template<typename _TreeNode>
size_t diameter(_TreeNode *node);
*/

#include <functional>

template<typename _TreeNode>
size_t diameter_impl(_TreeNode *node, size_t &max) {
    if (node != nullptr) {
        size_t left_max{}, right_max{};

        // DFS
        size_t left_height = diameter_impl(node->left, left_max);
        size_t right_height = diameter_impl(node->right, right_max);

        max = left_height + right_height + 1;
        max = std::max(max, left_max);
        max = std::max(max, right_max);

        return std::max(left_height, right_height) + 1;
    }

    return 0;
}

template<typename _TreeNode>
size_t diameter(_TreeNode *node) {
    size_t res{};
    diameter_impl(node, res);

    return res;
}