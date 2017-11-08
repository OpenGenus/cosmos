/*
 Part of Cosmos by OpenGenus Foundation

 tree comparer synopsis

template<typename _Tp, typename _Comp = std::equal_to<_Tp> >
class TreeComparer
{
public:
    using CNodeType = TreeNode<_Tp> const;
    using PCNodeType = std::shared_ptr<CNodeType>;

    bool isSameTree(PCNodeType p, PCNodeType q) const;

private:
    _Comp comp_;
};
 */

#include <stack>
#include <functional>
#include <memory>
#include "../tree_node/tree_node.cpp"

#ifndef TREE_COMPARER
#define TREE_COMPARER

template<typename _Tp, typename _Comp = std::equal_to<_Tp>>
class TreeComparer
{
public:
    using CNodeType = TreeNode<_Tp> const;
    using PCNodeType = std::shared_ptr<CNodeType>;

    bool isSameTree(PCNodeType const &f, PCNodeType const &s) const {
        std::stack<PCNodeType> first, second;
        first.push(f);
        second.push(s);

        // DFS
        while (!first.empty() || !second.empty())
        {
            // mining left
            while (first.top()!=nullptr
                   || second.top()!=nullptr)
            {
                // check not same node and not same value
                if (first.top()==nullptr
                    || second.top()==nullptr
                    || !comp_(first.top()->val, second.top()->val))
                    return false;

                first.push(first.top()->left);
                second.push(second.top()->left);
            }

            // escape if top is empty or right is empty
            while (!first.empty()
                   && ((first.top()==nullptr && second.top()==nullptr)
                       || (first.top()->right==nullptr && second.top()->right==nullptr)))
            {
                first.pop();
                second.pop();
            }

            if (!first.empty())
            {
                auto first_right = first.top()->right,
                     second_right = second.top()->right;
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
