'''
Link to the problem: https://leetcode.com/problems/maximize-distance-to-closest-person/

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, 
and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.



Example 1:


Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.

'''


class Solution:
    def maxDistToClosest(self, seats: list()) -> int:
        res = 0
        n = len(seats)
        f_id = seats.index(1)  
        last = f_id
        for i in range(n):
            if seats[i] == 1:
                res = max(res, (i - last) // 2)
                last = i
        return max(res, n - last - 1, f_id)  


# Creating object for the solution class and invoking the 'maxDistToClosest' function.


obj = Solution()
input = list(map(int, input('Enter the list: ').split(' ')))
res = obj.maxDistToClosest(input) 
print(res)   