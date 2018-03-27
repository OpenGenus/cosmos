#include<iostream>
#include <vector>
#include<climits>

/*
 * Part of Cosmos by OpenGenus Foundation
*/

using namespace std;
void countingSort(vector<int> arr,vector<int>& sortedA)
{
	int maxi_number=INT_MIN; // finding maximum element in array for making frequency array
	for(size_t i=0;i<arr.size();i++)
		if(arr[i]>maxi_number) maxi_number=arr[i];

	std::vector<int> freq(maxi_number+1,0); //maxi_number is the maximum element in the array. Inititalising frequency array to zero

	for(size_t i=0;i<arr.size();i++)
		freq[arr[i]]++;

	int j = 0; //pointer to current element for sorted array
    for(int i=0;i<=maxi_number;i++)
    {
        int tmp=freq[i];
        while(tmp--){
            sortedA[j] = i;
            j++;
        }
    }
}
int main()
{
	int i,n; //generalised for n numbers

	cout << "Give number of elements" << endl;
	cin >> n; // n is given as input by the user
	std::vector<int> arr(n);

	cout << "Enter all the elements" << endl;
	for(i=0;i<n;i++)
		cin >> arr[i];
	vector<int> sortedA(n+1); // stores sorted array

   	countingSort(arr,sortedA); // calls counting sort for array arr

   	cout<<"Sorted Array:  ";
   	for(size_t i=0;i<arr.size();i++)
   		cout<<sortedA[i]<<" ";
   	cout << endl;

   	return 0;
}