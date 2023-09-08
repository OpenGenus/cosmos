// Author: Karan Chawla
// Date: 8/8/17
// Part of Cosmos by OpenGenus Foundation
#include <iostream>
#include <vector>

using namespace std;

/* Function to find the unique number in an array */

int singleNumber(vector<int>& A) 
{
    int result = A[0];
    
    for(int i = 1 ; i < A.size() ; i++)
    {
        result = result^A[i];  
    }
    return result;
}

int main()
{
   vector<int> nums = {1, 1, 2, 3, 2, 4, 4, 3, 6};
   cout << singleNumber(nums);
  
   return(0);
}
