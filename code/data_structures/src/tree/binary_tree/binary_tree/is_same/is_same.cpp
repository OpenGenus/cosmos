/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * tree comparer synopsis
 *
 * template<typename _Tp, typename _Comp = std::equal_to<_Tp> >
 * class TreeComparer
 * {
 * public:
 *  using NodeType = TreeNode<_Tp>;
 *  using PNodeType = std::shared_ptr<NodeType>;
 *
 *  bool isSameTree(PNodeType p, PNodeType q) const;
 *
 * private:
 *  _Comp comp_;
 * };
 */

#include <stack>
#include <functional>
#include <memory>
#include "../node/node.cpp"

#ifndef TREE_COMPARER
#define TREE_COMPARER

template<typename _Tp, typename _Comp = std::equal_to<_Tp>>
class TreeComparer
{
public:
    using NodeType = TreeNode<_Tp>;
    using PNodeType = std::shared_ptr<NodeType>;

    bool isSameTree(PNodeType const &f, PNodeType const &s) const
    {
        std::stack<PNodeType> first, second;
        first.push(f);
        second.push(s);

        // DFS
        while (!first.empty() || !second.empty())
        {
            // mining left
            while (first.top() != nullptr
                   || second.top() != nullptr)
            {
                // check not same node and not same value
                if (first.top() == nullptr
                    || second.top() == nullptr
                    || !comp_(first.top()->value(), second.top()->value()))
                    return false;

                first.push(first.top()->left());
                second.push(second.top()->left());
            }

            // escape if top is empty or right is empty
            while (!first.empty()
                   && ((first.top() == nullptr && second.top() == nullptr)
                       || (first.top()->right() == nullptr && second.top()->right() == nullptr)))
            {
                first.pop();
                second.pop();
            }

            if (!first.empty())
            {
                auto first_right = first.top()->right(),
                     second_right = second.top()->right();
                first.pop();
                second.pop();
                first.push(first_right);
                second.push(second_right);
            }
        }

        return true;
    }

private:
    _Comp comp_;
};

#endif // TREE_COMPARER
