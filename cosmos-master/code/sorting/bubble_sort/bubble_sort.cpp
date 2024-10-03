/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>
#include <vector>
#include <algorithm>

void bubble_sort(std::vector<int> &v)
{
	for(int i=0; i < v.size(); ++i)
		for(int j=i+1; j < v.size(); ++j)
		{
			if (v[i] > v[j])
				std::swap(v[i],v[j]);
		}
}
int main()
{
	std::vector<int> input_array;
	input_array.push_back(2);
	input_array.push_back(7);
	input_array.push_back(1);
	input_array.push_back(10);
	input_array.push_back(-3);
	input_array.push_back(8);
	bubble_sort(input_array);
	for(auto x :input_array)
		std::cout<<x<<" ";
	std::cout<<"\n";
	return 0;
}
