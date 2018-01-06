/*
 Part of Cosmos by OpenGenus Foundation
 */

#ifndef path_sum_hpp
#define path_sum_hpp

#include <memory>
#include <vector>
#include <functional>
#include "../node/node.cpp"

template<typename _Ty, typename _Compare = std::equal_to<_Ty>, class _TreeNode = TreeNode<_Ty>>
class PathSum
{
private:
    template<typename _T>
    using Node = _TreeNode;
    template<typename _T>
    using PNode = std::shared_ptr<Node<_T>>;
    using size_type = size_t;

public:
    enum class PathType
    {
        Whole,
        Part
    };

    PathSum(PathType py = PathType::Whole) :compare_(_Compare()), path_type_(py) {};

    ~PathSum() = default;

    size_type countPathsOfSum(PNode<_Ty> root, _Ty sum);

    std::vector<std::vector<_Ty>> getPathsOfSum(PNode<_Ty> root, _Ty sum);

private:
    _Compare compare_;
    PathType path_type_;

    void getPathsOfSumUp(PNode<_Ty> root,
                         std::vector<_Ty> prev,
                         _Ty prev_sum,
                         _Ty const &sum,
                         std::vector<std::vector<_Ty>> &res);
};

#include "path_sum.cpp"

#endif /* path_sum_hpp */
