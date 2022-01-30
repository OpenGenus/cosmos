def combinationSum(candidates, target):
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
    result_set = []
    backtrack(0, sorted(candidates), target, 0, result_set, [])
    return result_set


def backtrack(pos, candidates, target, currentSum, result_set, sequence):
    """
    Helper function for backtracking. Initially does a DFS traversal on each
    index to check all combinations of subsets to see if they sum to the target
    sum. 

    Args:
        pos: current pivot index
        candidates: candidates list (main list of pickable integers)
        currentSum: current sum of the list
        result_set: list to store all result_set
        sequence: list being used to contain elements relevent to the current DFS

    Returns:
        None
    """
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


if __name__ == "__main__":
    arr = [2, 3, 6, 7]
    print(combinationSum(arr, 7))
