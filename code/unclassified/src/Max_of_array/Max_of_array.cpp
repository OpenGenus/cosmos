 #include <iostream>
using namespace std;

int main() {
	//the largest number in an array;
	//declaring an array
	int n;
	cout<<"enter the size of the array"<<endl; //getting the number of elements of the array
	cin>>n;//taking input
	int arr[n]; //creating array arr
	for(int i=0;i<n;i++) //looping to get to each element in array
	{
	    cout<<"enter the"<<i<<"th element"<<endl;
	    cin>>arr[i];
	}
	cout<<"Finding maximum"<<endl;
	int max=arr[0]; //lets assume maximum is at 0th position
	for(int i=1;i<n;i++)
	{
	    if(arr[i]>max) //if any element from 1 to n is greater than given max value
	    {
	        max=arr[i]; //replace the value of max with the coressponding value
	    }
	}
	cout<<"the maximum is"<<max;
	
}
