class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum=0,i,j=0;
        vector<int>arr;
        for(i=1;i<nums.size();)
        { 
        sum=nums[j]+nums[i];
        if(sum==target)
        {
         arr.push_back(j);
         arr.push_back(i);
         break;
        }
        
     if (i == nums.size() - 1)
		{
		 j++;
         i=j+1;
		}
        else
        {
            i++;
        }
	}

	return arr;
    }
};
