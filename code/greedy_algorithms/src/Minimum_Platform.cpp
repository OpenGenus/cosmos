/* Problem Statement: Given Arrival and Departure Time of all trains that visit the railway station,
 * Calculate the minimum number of platforms required such that no train has to wait.
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<" Enter the number of trains: ";
	cin>>n;
	int arr[n];
	// array to store arrival time
	int depart[n];
	// array to store departure time
	int min_p = 0;
	// minimum no. of platform required
	int m = 0;
	cout<<"\n Enter the arrival times of n trains:  ";
	for(int i = 0;i < n;i ++)
	{
		cin>>arr[i];
	}
	cout<<"\n Enter the departure times of n trains:  ";
	for(int i = 0;i < n;i ++)
	{
		cin>>depart[i];
	}
	sort(arr, arr + n);
	// sort arrival time 
	sort(depart, depart + n);
	// sort departure time  
	int i = 0; int j = 0;
	// i and j are pointers to arrival time and departure time respectively
	while(i < n && j < n)
	{   // compare the arrival and departure time of trains until either from list exhaust 
		if(arr[i] <= depart[j])
		{   // =>we need one more platform for the train to be arrived
			m += 1;
			i ++;
		}
		else
		{   // =>there is a vacant platform which could be used
		   	m -= 1;
			j ++;
		}
	min_p=max(min_p, m);
	}
	cout<<min_p<<endl;
	return 0;
}
