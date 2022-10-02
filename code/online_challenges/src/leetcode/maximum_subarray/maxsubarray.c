class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        int max_overall=INT_MIN;
        int max_ending=0;
        for(int i=0;i<len;i++){
            if(nums[i]<=max_ending+nums[i]){
                max_ending+=nums[i];
            }
            else{
                max_ending=nums[i];
            }
            if(max_ending>max_overall){
                max_overall=max_ending;
            }
      }
        return max_overall;
    }
    };