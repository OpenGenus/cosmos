//CODE

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    /* 
        Parameters:
            nums - The input array; 
            cuts - How many cuts are available (cuts = #groups - 1); 
            max - The maximum of the (sum of elements in one group);
        Return:
            Whether we can use at most 'cuts' number of cuts to segment the entire array, 
            such that the sum of each group will not exceed 'max'.
     */
    bool doable (const vector<int>& nums, int cuts, long long max) {
        
        // 'acc' is the temporary accumulator for the currently processed group.
        
        int acc = 0;
        for (int num : nums) {
            
            // If the current processed element in this array is larger than 'max', we cannot segment the array.
            // (Reason is straightforward, if 'nums' is [10, 2, 3, 5] and 'max' is 6, even you can have 3 cuts
            // (by which you can cut array as [[10], [2], [3], [5]]), the group containing 10 will be larger than 6, 
            //  there is no way to do this).
            // Ps: This step is unnecessary in this solution. Because 'left' in the splitArray() function can assure 
            // 'max' will be larger than every single element. I just want to write a generalized doable() function :)
            
            if (num > max) return false;
            
            // If the (sum of the currently processed group) + (current element) is smaller than max, we can add current 
            // element into this group.
            
            else if (acc + num <= max) acc += num;
            
            // If not, we will make a cut before this element, and this element will be the first element in the new group.
            
            else {
                --cuts;
                acc = num;
                
                // If we've used up all cuts, this means this 'max' is not doable.
                if (cuts < 0) return false;
            }
        }
        
        // If we can reach here, this means we've used at most 'cuts' cut to segment the array, and the sum of each groups is
        // not larger than 'max'. Yeah!
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        // Use long long to avoid overflow.
        long long left = 0, right = 0;
        // The smallest possible value ('left') is the the value of the largest element in this array.
        // The largest possible value ('right') is the sum of all elements in this array.
        for (int num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        
        // Use binary search, find the lower bound of the possible (minimum sum of groups within m - 1 cuts).
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (doable(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
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
        int n,m;
        cout << "Enter the Quantity of Array Elements: ";
        cin >> n;
        cout << "Input " << n << " Array elements: ";
        vector<int> nums(n);
        for (auto &it : nums) {
            cin >> it;
        }
        cout << "Enter the value of m: ";
        cin >> m;
        Solution ob;
        cout << "The largest sum among the " << m << " subarray is " << ob.splitArray(nums, m) << endl;
    }
    return 0;
}