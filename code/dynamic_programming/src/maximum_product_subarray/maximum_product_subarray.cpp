/*

Read Problem Description Here - https://leetcode.com/problems/maximum-product-subarray/

Test Cases - 

Input: [2,3,-2,4]
Output: 6

Input: [-2,0,-1]
Output: 0

*/

#include<iostream>
#include<climits>
using namespace std;

int maxProdSub(int* arr, int n)
{
	int positiveProd = 1, negativeProd = 1;
	int ans = INT_MIN;

	for(int i = 0 ; i < n ; i++)
	{
		int extraPositive = max(positiveProd * arr[i], max(negativeProd * arr[i], arr[i])); 
		// dummy variable for getting the current max
		int extraNegative = min(positiveProd * arr[i], min(negativeProd * arr[i], arr[i])); 
		// dummy variable for getting the current min 

		positiveProd = extraPositive; // save current max
		negativeProd = extraNegative; // save current min

		if(ans < positiveProd) // if global ans is lesser than current answer, save
		ans = positiveProd;

		if(arr[i] == 0) // if 0 is encountered we reset the values of max and min
		{
			positiveProd = 1;
			negativeProd = 1;
		}
	}

	return ans;
}

int main()
{
	int n; // size input
	cin>>n;

	int arr[n]; // array input
	for(int i = 0 ; i < n ; i++)
	cin>>arr[i];

	cout<<maxProdSub(arr, n);
}
