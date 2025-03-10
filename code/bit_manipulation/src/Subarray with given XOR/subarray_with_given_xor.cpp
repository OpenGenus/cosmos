// Part of Cosmos by OpenGenus Foundation
int Solution::solve(vector<int> &nums, int target) {
   
    // we have to check how many subarrays having xor of target
   
    // if any subarray has xor value of total , if total ^ target = p , & p is present in the map
   
    // then this will give one answer
   
    unordered_map< int  , int > mp;
   
   // mp[0]=1;
   
    int xor_val=0;
   
    int count=0;
   
    for(int i=0;i<nums.size();i++)
    {
        xor_val = xor_val ^ nums[i];
       
        if(xor_val==target)
        {
            count++;
        }
       
        if(mp.find(xor_val ^ target)!=mp.end())
        {
            count+=(mp[xor_val ^ target]);
        }
       
        mp[xor_val]++;
    }
   
    return count;
   
}
