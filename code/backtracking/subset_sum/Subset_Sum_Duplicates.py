def combinationSum(self, candidates, target):
    """
    Problem description:

    Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
    find all unique combinations in C where the candidate numbers sums to T.

    The same repeated number may be chosen from C unlimited number of times.
    
    Args:
        candidates: list of pickable integers
        target: target sum

    Returns:
        List of subsets that sum to the target sum of target
    """
    def backtrack(pos, candidates, target, currentSum, result_set, sequence):
        if currentSum == target:
            result_set.append(sequence[:])
        elif currentSum < target:
            for i in range(pos, len(candidates)):
                newSum = currentSum + candidates[i]
                if newSum > target:
                    break
                sequence.append(candidates[i])
                backtrack(i, candidates, target, newSum, result_set, sequence)
                sequence.pop()
    
    result_set = []
    backtrack(0, sorted(candidates), target, 0, result_set, [])
    return result_set