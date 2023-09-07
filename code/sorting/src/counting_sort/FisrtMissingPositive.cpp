/* 
Given an unsorted integer array, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.
Example 1:
Input: nums = [1,2,0]
Output: 3
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
 
Constraints:
    1 <= nums.length <= 5 * 105
    -231 <= nums[i] <= 231 - 1
*/

#include<bits/stdc++.h>

using namespace std; 

//Algorithm
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int correct = nums[i];
            if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[correct - 1]){
                swap(nums[i], nums[correct - 1]);
            }else{
                i++;
            }
        }
        for(int j=0; j < nums.size(); j++){
            if(nums[j] != j + 1) return j + 1;
        }
        return nums.size() + 1;
    }
};

// Driver Code Starts.
int main()
{
    int t;
    cout << "Inpur the number of Test cases :";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "Enter the Quantity of Numbers: ";
        cin >> n;
        cout << "Input " << n << " Numbers: ";
        vector<int> nums(n);
        for (auto &it : nums) {
            cin >> it;
        }
        Solution ob;
        cout << "The First Missing Positive Integer is " << ob.firstMissingPositive(nums) << endl;
    }
    return 0;
}

/* 

Approach : Implement Count Sort
Idea is to swap each positive integer you encounter to its "rightful" place at index (x-1) where x is the integer

Time Complexity : O(n)
Auxiliary Space : O(1)

*/