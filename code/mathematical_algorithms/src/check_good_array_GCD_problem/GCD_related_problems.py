import math
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        '''
        ' 1. This problem is equivalent to "find two number and its linear combination equal to 1",
        '    Because If we can find two number and take coefficient of other numbers is zero.
        '
        ' 2. Then this problem be considered as "find two number and they are coprime",
        '    Bacause this the EX_GCD conclude 
        ' 
        ' 3. So far, we should solve "find two number are coprime from a array",
        '    we can to calculate all number gcd whether is equal 1, 
        '    exmaple1: gcd(a1, gcd(a2, gcd(a3, a4))) If its result is 1, then exist two or more number is coprime
        '    because once its intermediate result has 1 when the array have coprime number pair, then gcd(1, anynumber) = 1  
        '''
        ans = nums[0]
        for num in nums:
            ans = math.gcd(ans, num)
        return ans == 1
