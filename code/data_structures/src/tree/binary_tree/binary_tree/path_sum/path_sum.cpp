/*
 * Part of Cosmos by OpenGenus Foundation
 */

#ifndef path_sum_cpp
#define path_sum_cpp

#include "path_sum.hpp"
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>
#include <functional>

// public
template<typename _Ty, typename _Compare, class _TreeNode>
auto
PathSum<_Ty, _Compare, _TreeNode>::countPathsOfSum(PNode<_Ty> root, _Ty sum)->size_type
{
    if (path_type_ == PathType::Whole)
        return getPathsOfSum(root, sum).size();
    else        // path_type_ == PathType::Part
    {
        if (root == nullptr)
        {
            return {};
        }

        return getPathsOfSum(root, sum).size()
               + countPathsOfSum(root->left(), sum)
               + countPathsOfSum(root->right(), sum);
    }
}

template<typename _Ty, typename _Compare, class _TreeNode>
std::vector<std::vector<_Ty>>
PathSum<_Ty, _Compare, _TreeNode>::getPathsOfSum(PNode<_Ty> root, _Ty sum)
{
    std::vector<std::vector<_Ty>> res{};
    getPathsOfSumUp(root, {}, {}, sum, res);

    return res;
}

// public end

// private

template<typename _Ty, typename _Compare, class _TreeNode>
void
PathSum<_Ty, _Compare, _TreeNode>::getPathsOfSumUp(PNode<_Ty> root,
                                                   std::vector<_Ty> prev,
                                                   _Ty prev_sum,
                                                   _Ty const &sum,
                                                   std::vector<std::vector<_Ty>> &res)
{
    if (root != nullptr)
    {
        auto &curr = prev;
        curr.push_back(root->value());

        auto &curr_sum = prev_sum;
        curr_sum += root->value();

        if (path_type_ == PathType::Whole)
        {
            if (root->left() == nullptr
                && root->right() == nullptr
                && compare_(curr_sum, sum))
                res.push_back(curr);
        }
        else        // path_type_ == PathType::Part
        if (compare_(curr_sum, sum))
            res.push_back(curr);


        getPathsOfSumUp(root->left(), curr, curr_sum, sum, res);
        getPathsOfSumUp(root->right(), curr, curr_sum, sum, res);
    }
}

// private end

#endif /* path_sum_cpp */
