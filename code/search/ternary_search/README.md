/* Part of Cosmos by OpenGenus Foundation */

# Ternary Search
A ternary search algorithm is a technique in computer science for finding the minimum or maximum of a unimodal function. A ternary search determines either that the minimum or maximum cannot be in the first third of the domain or that it cannot be in the last third of the domain, then repeats on the remaining third. A ternary search is an example of a divide and conquer algorithm.

## The function
Assume we are looking for a maximum of f(x) and that we know the maximum lies somewhere between A and B. For the algorithm to be applicable, there must be some value x such that
for all a,b with A ≤ a < b ≤ x, we have f(a) < f(b), and
for all a,b with x ≤ a < b ≤ B, we have f(a) > f(b).

### Iterative algorithm
def ternarySearch(f, left, right, absolutePrecision):
    """
    Find maximum of unimodal function f() within [left, right]
    To find the minimum, reverse the if/else statement or reverse the comparison.
    """
    while True:
        #left and right are the current bounds; the maximum is between them
        if abs(right - left) < absolutePrecision:
            return (left + right)/2

        leftThird = left + (right - left)/3
        rightThird = right - (right - left)/3

        if f(leftThird) < f(rightThird):
            left = leftThird
        else:
            right = rightThird


### Recursive algorithm
def ternarySearch(f, left, right, absolutePrecision):
    '''
    left and right are the current bounds; 
    the maximum is between them
    '''
    if abs(right - left) < absolutePrecision:
        return (left + right)/2

    leftThird = (2*left + right)/3
    rightThird = (left + 2*right)/3

    if f(leftThird) < f(rightThird):
        return ternarySearch(f, leftThird, right, absolutePrecision) 
    else:
        return ternarySearch(f, left, rightThird, absolutePrecision)
        
        
 ## Collaborative effort by [OpenGenus](https://github.com/opengenus)
