

class Solution {
public:
    vector<int> grayCode(int n) {
        
        if(n==1)
        {
            return {0,1};
        }
        
        vector<int> ans=grayCode(n-1);
        
        for(int ind=ans.size()-1;ind>=0;ind--)
        {
            ans.push_back(ans[ind]+pow(2,n-1));
        }
        
        return ans;
    }
};