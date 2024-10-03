// Part of OpenGenus/cosmos
// Author: Karan Chawla
// Date: 17th Oct '17

#include <iostream>
#include <vector>
#include <climits> 
#include <unorderd_map>

using namespace std;

// Function returns the size of minimum subarray with the same 
// degree as the original array. Degree: Largest frequency of an
// element in the array

int minSubArrayDegree(const vector<int> &nums)
{
	unorderd_map<int, vector<int>> map;
	int min_dist = INT_MIN;
	int degree = 0;
	//create counter
	for(int i = 0; i < nums.size(); i++)
	{
		map[nums[i]].push_back(i);
		int size = map[nums[i]].size()
		degree = max(degree, size);
	}

	for(auto m: map)
	{
		vector<int> temp = m.second;
		if(temp.size() == degree)
			min_dist = min(min_dist, temp[temp.size() - 1] - temp[0] + 1);
	}

	return min_dist;
}

int main()
{
  vector<int> nums = {0, 2, 3, 4, 1, 1};
  cout << minSubArrayDegree(nums) << endl;
  // returns 2
  return(0);
}
