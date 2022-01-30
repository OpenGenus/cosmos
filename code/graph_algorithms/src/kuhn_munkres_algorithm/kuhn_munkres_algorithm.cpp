/*
 * Part of Cosmos by OpenGenus Foundation
 *
 * Kuhn-Munkres algorithm: find the perfect matching in a balanced and weighted bipartite graph
 * that gives the maximum sum of weights.
 */
#include <memory>
#include <vector>
#include <type_traits>
#include <limits>
#include <algorithm>
#include <iostream>
#include <initializer_list>

template
<
    typename _WeightType,
    typename = std::enable_if<
        std::is_integral<_WeightType>::value && std::is_signed<_WeightType>::value>::type
>
class KuhnMunkresAlgorithm
{
public:
    /*
     * InputVector[i][j] contains the weight of the edge between Left node i and right node j.
     * Let UpperLimit = std::numeric_limits<_WeightType>::max()/3 and LowerLimit = -UpperLimit,
     * please make sure weights of edges are within range (LowerLimit, UpperLimit).
     * If there is no edge between Left node i and right node j, set the weight to LowerLimit.
     * At least one perfect matching must exist in the input bipartite graph.
     */
    using InputType = std::vector<std::vector<_WeightType>>;

public:
    explicit KuhnMunkresAlgorithm(const std::shared_ptr<InputType> Input) noexcept
        : LeftsCount_(Input->size()),
        RightsCount_((*Input)[0].size()),
        leftsVisited_(LeftsCount_),
        rightsVisited_(RightsCount_),
        leftsLabel_(LeftsCount_),
        rightsLabel_(RightsCount_),
        Input_{Input}
    {
    }

    /*
     * Returns the perfect matching that gives the maximum sum of weights, represented by a vector.
     * The index of the vector is the index of a right node. The element stored in the vector is the
     * index of the Left node that is matched with the right node.
     */
    std::vector<ptrdiff_t> run() noexcept
    {
        // Initialize the matching. At the beginning, no match exists in the matching.
        std::vector<ptrdiff_t> matching(RightsCount_,
                                        -1 /* -1 means this right node is unmatched. */);

        // Initialize labels of Left nodes (labels of right nodes are already initialized to 0).
        for (ptrdiff_t Left = 0; Left < LeftsCount_; ++Left)
        {
            _WeightType maxWeight = LowerLimit_;

            for (ptrdiff_t right = 0; right < RightsCount_; ++right)
                maxWeight = std::max(maxWeight, (*Input_)[Left][right]);

            leftsLabel_[Left] = maxWeight;
        }

        for (ptrdiff_t Left = 0; Left < LeftsCount_; ++Left)
        {
            leftsVisited_.assign(LeftsCount_, false);
            rightsVisited_.assign(RightsCount_, false);
            diff_ = UpperLimit_;

            while (!dfs(Left, matching)) // This loop won't exit until an augmenting path is found.
            {
                // Update labels.
                for (ptrdiff_t i = 0; i < LeftsCount_; ++i)
                    if (leftsVisited_[i])
                        leftsLabel_[i] -= diff_;

                for (ptrdiff_t j = 0; j < RightsCount_; ++j)
                    if (rightsVisited_[j])
                        rightsLabel_[j] += diff_;

                leftsVisited_.assign(LeftsCount_, false);
                rightsVisited_.assign(RightsCount_, false);
                diff_ = UpperLimit_;
            }
        }

        return matching;
    }

private:
    bool dfs(const ptrdiff_t Left, std::vector<ptrdiff_t> &matching) noexcept
    {
        leftsVisited_[Left] = true;

        // Try to find an augmenting path.
        for (ptrdiff_t right = 0; right < RightsCount_; ++right)
        {
            if (rightsVisited_[right])
                continue;       // Only an unvisited right node counts.

            _WeightType t = leftsLabel_[Left] + rightsLabel_[right] - (*Input_)[Left][right];
            if (t == 0) // In an equal subgraph.
            {
                rightsVisited_[right] = true;
                if (matching[right] == -1 || dfs(matching[right], matching))
                {
                    // Augmenting path found, update the matching.
                    matching[right] = Left;
                    return true;
                }
            }
            else
                diff_ = std::min(diff_, t);
        }

        return false;
    }

private:
    const ptrdiff_t LeftsCount_;
    const ptrdiff_t RightsCount_;
    _WeightType diff_ = UpperLimit_;
    std::vector<bool>                      leftsVisited_;
    std::vector<bool>                      rightsVisited_;
    std::vector<_WeightType>               leftsLabel_;
    std::vector<_WeightType>               rightsLabel_;
    const std::shared_ptr<const InputType> Input_;
public:
    static constexpr _WeightType UpperLimit_ = std::numeric_limits<_WeightType>::max() / 3;
    static constexpr _WeightType LowerLimit_ = -UpperLimit_;
};

int main()
{
    const int non = KuhnMunkresAlgorithm<int>::LowerLimit_;
    const auto input = std::make_shared<KuhnMunkresAlgorithm<int>::InputType>(
        std::initializer_list<std::vector<int>>{
        { 200, non, 180, 180, non, 190, non, 195 },
        { non, non, non, 170, 185, 186, 187, non },
        { non, 189, 170, 166, 160, non, non, 191 },
        { 160, 167, non, non, 200, 198, 195, 202 },
        { non, 170, 184, non, 202, 198, 169, 205 },
        { non, non, 187, 204, non, 185, 200, non },
        { 170, 170, 170, 170, 170, 170, 170, 170 },
        { non, 170, 169, 174, non, non, non, 197 }
    });
    KuhnMunkresAlgorithm<int> algorithm{input};
    std::vector<ptrdiff_t> result = algorithm.run();
    for (ptrdiff_t i = 0; i < result.size(); ++i)
        std::cout << "right node " << i << " is matched with left node " << result[i] << ".\n";
    std::cin.get();
    return 0;
}
