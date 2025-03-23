class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        mf=nums[0]
        me=nums[0]
        
        for i in range(1,len(nums)):
            me=max(nums[i],me+nums[i])
            mf=max(mf,me)
        return mf