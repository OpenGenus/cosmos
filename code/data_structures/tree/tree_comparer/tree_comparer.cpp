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

#include "../tree_node/tree_node.cpp"
#include <stack>
#include <functional>

#ifndef TREE_COMPARER
#define TREE_COMPARER

template<typename _Tp, typename _Comp = std::equal_to<_Tp> >
class TreeComparer
{
public:
    using CNodeType = TreeNode<_Tp> const;
    using PCNodeType = std::shared_ptr<CNodeType>;

    bool isSameTree(PCNodeType const &p, PCNodeType const &q) const {
        std::stack<PCNodeType> stp, stq;
        stp.push(p);
        stq.push(q);

        // DFS
        while (!stp.empty() || !stq.empty())
        {
            // mining left
            while (stp.top() != nullptr
                   || stq.top() != nullptr)
            {
                // check not same node and not same value
                if (stp.top() == nullptr
                    || stq.top() == nullptr
                    || !comp_(stp.top()->val, stq.top()->val))
                    return false;

                stp.push(stp.top()->left);
                stq.push(stq.top()->left);
            }

            // escape if top is empty or right is empty
            while (!stp.empty()
                   && ((stp.top() == nullptr && stq.top() == nullptr)
                       || (stp.top()->right == nullptr && stq.top()->right == nullptr)))
            {
                stp.pop();
                stq.pop();
            }

            if (!stp.empty())
            {
                auto right_p = stp.top()->right, right_q = stq.top()->right;
                stp.pop();
                stq.pop();
                stp.push(right_p);
                stq.push(right_q);
            }
        }

        return true;
    }

private:
    _Comp comp_;
};

#endif // TREE_COMPARER
