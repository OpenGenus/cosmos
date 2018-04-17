// Part of Cosmos by OpenGenus Foundation
// Author: Karan Chawla
// 15th Oct '17
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//Utility function to apply kadane's algorithm
//Returns the maximum sub in an array
int kadane(vector<int> &nums, int &start)
{
    //Initialize variables
    int sum = 0;
    int max_sum = INT_MAX;

    int finish = -1;
    int local_start = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > max_sum)
        {
            max_sum = sum;
            start = local_start;
            finish = i;
        }
    }

    if (finish == -1)
        return max_sum;

    //When all numbers are negative
    max_sum = nums[0];
    start = finish = 0;

    // Find maximum element in the array
    for (size_t i = 0; i < nums.size(); i++)
        if (nums[i] > max_sum)
        {
            max_sum = nums[i];
            start = finish = i;
        }

    return max_sum;
}


// Function to find maximum sum rectangle
void findMaxSum(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int maxSum = INT_MIN;
    int final_left, final_right, final_bottom, final_top;

    int left, right, i, sum, start, finish = 0;
    vector<int> temp(row, 0);

    for (left = 0; left < col; left++)
        for (right = left; right < col; right++)
        {
            for (i = 0; i < row; i++)
                temp[i] += matrix[i][right];

            sum = kadane(temp, start);

            if (sum > maxSum)
            {
                maxSum = sum;
                final_left = left;
                final_right = right;
                final_top = start;
                final_bottom = finish;
            }
        }

    cout << "(top, left)" << final_top << " " << final_left;
    cout << "(bottom, right)" << final_bottom << " " << final_right;
    cout << "Maximum sum" << maxSum;

    return;
}

int main()
{
    vector<vector<int>> nums = {{1, 2, -1, -4, -20},
                                {-8, -3, 4, 2, 1},
                                {3, 8, 10, 1, 3},
                                {-4, -1, 1, 7, -6}};

    findMaxSum(nums);

    return 0;
}
