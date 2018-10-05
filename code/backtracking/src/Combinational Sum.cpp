//https://www.geeksforgeeks.org/combinational-sum/

#include<bits/stdc++.h>
using namespace std;
void ans(vector<int>v ,int startindex,int n,int osize,int output[],int sum)
{
	if(sum<0)
	return;
	if(startindex==n)
	{
		if(sum==0)
		{
			for(int i=0;i<osize;i++)
			cout<<output[i]<<" ";
			cout<<endl;
		}
		return;
		
	}
	ans(v,startindex+1,n,osize,output,sum);
	int smalloutput[1000];
	int smallsize;
	//copy all the elements of previous array into new array
	if(sum>0)
	{
		
	
	int i=0;
	for(i=0;i<osize;i++)
	{
		
	}
	output[i]=v[startindex];
    }
	ans(v,startindex,n,osize+1,output,sum-v[startindex]);
}
int main()
{
	int n=4;
	int arr[]={7,2,6,5};
	int sum=16;
	int nsize;
	sort(arr,arr+n);
    if (n==0 || n==1)
        nsize=n;
 
    int temp[n];
 
    int j = 0;
    for (int i=0; i<n-1; i++)
 
            if (arr[i] != arr[i+1])
            temp[j++] = arr[i];
 

    temp[j++] = arr[n-1];
 

    for (int i=0; i<j; i++)
        arr[i] = temp[i];

    nsize=j;
    vector<int> v;
    for(int i=0;i<n;i++)
    v.push_back(arr[i]);
    int output[100];
    ans(v,0,nsize,0,output,sum);

}
