#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int> &arr, int n)
{
	int key;
	int j;
	for(int i=1;i<n;i++)
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
	int arraySize;
	cin>>arraySize;
	vector<int> inputArray(arraySize);
	for(int i=0;i<arraySize;i++)
	{
		cin>>inputArray[i];
	}
	insertionSort(inputArray, arraySize);

	for(int i=0;i<arraySize;i++)
	{
		cout<<inputArray[i]<<" ";
	}
	cout<<endl;
	return 0;
}

