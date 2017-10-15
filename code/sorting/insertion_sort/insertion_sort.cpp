#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Part of Cosmos by OpenGenus Foundation
void insertionSort(vector<int> &arr)
{
	int key;
	int j;
	for(int i=1;i<arr.size();i++)
	{
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main()
{
	vector<int> inputArray;
	for(int i; cin >> i;)
	{
		inputArray.push_back(i);
	}
	insertionSort(inputArray);

	for(int i=0;i<inputArray.size();i++)
	{
		cout<<inputArray[i]<<" ";
	}
	cout<<endl;
	return 0;
}