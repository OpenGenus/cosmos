# What is PoliceMan Thieve problem?

It is a Greedy based approach to a problem which tells that we are given an array of n elements. Each element of the array has either a policeman or a thief, one thief can be caught by one police and we have to find the maximum number of thieves that can be caught by the police if a policeman can catch a thief k units away from him.

# Example 

array = {T, P, P, P, T , T, T}
K = 2.

Output − 3

Explanation - 

P at index 1 will catch T at index 0.
P at index 2 will catch T at index 4.
P at index 3 will catch T at index 5.

# Brute Force solution

A brute force approach would be to check all feasible sets of combinations of police and thief and return the maximum size set among them. Its time complexity is exponential and it can be optimized if we observe an important property.

# Efficient Approach

An efficient approach would be to use greedy solution and it can work in two ways, either catch all thieves nearest to a policeman or catch thieves farthest to the policeman. But in both case, the most optimum solution is not found as both lags are some case where a policeman has to catch a thieve at a certain distance from him.
We will start with the indexes of the first policeman and thief. If |index(P1) - index(T1)| <= k, the thief can be caught and we will check for the next police-thief pair. Otherwise, we will increase min(p,t) and check for the next index of police and thief. This check is to be done until all policemen and thieves are checked and in the end the number of thieves caught is printed.

# Complexity 

Time Complexity: O(N) 
Auxiliary Space: O(N)