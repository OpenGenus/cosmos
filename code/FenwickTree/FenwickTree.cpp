// Binary indexed tree or fenwick tree
// Space Complexity: O(N) for declaring another array of N=size num_of_elements
// Time Complexity: O(logN) for each operation(update and query as well)
// original array for storing values for later lookup
// Part of Cosmos by OpenGenus Foundation
#include <bits/stdc++.h>
using namespace std;
int num_elements;
void update(int x,int delta,vector<int > &bit)
{
	// x&(-x) gives the last set bit in a number x
	for(;x<=num_elements;x+=x&-x)
		bit[x]+=delta;
}
long long query(int x,vector<int> &bit)
{
	long long sum=0;
	// x&(-x) gives the last set bit in a number x
	for(;x>0;x-=x&-x)
		sum+=bit[x];
	return sum;
}
int main()
{
	int num_queries,left_index,right_index;
	cout<<"Enter number of elements\n";
	cin>>num_elements;
	vector<int> container,bit(num_elements+1,0);
	for(int i=0;i<num_elements;i++)
	{
		cout<<"Enter element\n";
		int temp;
		cin>>temp;
		container.push_back(temp);
		update(i+1,temp,bit);
	}
	cout<<"Enter number of queries\n";
	cin>>num_queries;
	for(int i=0;i<num_queries;i++)
	{
		cout<<"Enter start index(1 indexed)\n";
		cin>>left_index;
		cout<<"Enter end index(1 indexed)\n";
		cin>>right_index;
		if(left_index>right_index)
		{
			cout<<"Invalid range\n";
			continue;
		}
		cout<<"Sum in given range is\n";
		cout<<query(right_index,bit)-query(left_index-1,bit)<<endl;
	}
	return 0;
}
