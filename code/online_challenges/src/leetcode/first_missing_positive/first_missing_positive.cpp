class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       map<int,int> m;
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                m[nums[i]]++;
        int prev=1;
        if(m.begin()->first!=1)
            return 1;
        map<int,int> :: iterator itr;
        for(itr=m.begin();itr!=m.end();itr++)
        {
            if(itr->first!=prev)
                return prev;
            prev+=1;
        }
        return prev;
        
    }
};