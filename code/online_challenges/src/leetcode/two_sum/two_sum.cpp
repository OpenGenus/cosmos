#include<bits/stdc++.h>
using namespace std;
//O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int>res;

        for(int i=0;i<(int)nums.size();++i){
            for(int j=i+1;j<(int)nums.size();++j){
                if(nums[i]+nums[j]==target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }

        return res;
    }
};

int main(){
    vector<int>numbers {2,7,11,15};
    vector<int>result;

    result = Solution().twoSum(numbers, 9);

    for(int i=0;i<(int)result.size();++i){
        cout<<result[i]<< " ";
    }

    return 0;
}
