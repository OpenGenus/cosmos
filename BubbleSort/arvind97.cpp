#include <iostream>
using namespace std;

int main()
{
    int arr[20], n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j]  = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<"\n";
}

