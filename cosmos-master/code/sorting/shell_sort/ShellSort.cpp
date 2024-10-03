	#include <iostream>
	#include <vector>
	#include <algorithm> 

	using namespace std;

	void shellSort(vector<int> &ar, int size)
	{
		int j;
		for (int gap = size / 2; gap > 0; gap /= 2)
	  	{
	    	for (int i = gap; i < size; i++)
	    	{
	      		int temp = ar[i];
	      		for (j = i; j >= gap && temp < ar[j - gap]; j -= gap)
	      		{
	        		ar[j] = ar[j - gap];
	      		}
	      		ar[j] = temp;
	    	} 
	  	}
	}

	int main()
	{
		int nSize;
		cin>>nSize;
		vector<int> inputArray(nSize);
		for(int i=0;i<nSize;i++)
		{
			cin>>inputArray[i];
		}
		shellSort(inputArray,nSize);
		for(int i=0;i<nSize;i++)
		{
			cout<<inputArray[i]<<" ";
		}
		cout<<endl;
		return 0;
	}