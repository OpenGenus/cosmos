#include <iostream>
#include<climits>
using namespace std;

int solve(int arr[],int start,int end)
{
    if(start>end)
        return 0;

    if(start==end)
        return arr[start];

    int mid = (start+end)/2;
    int a1 = solve(arr,start,mid);
    int a2 = solve(arr,mid+1,end);

    int tempsum = 0;
    int leftsum = INT_MIN,rightsum=INT_MIN;

    for(int i=mid;i>=start;i--)
    {
        tempsum+=arr[i];
        if(tempsum>leftsum)
            leftsum = tempsum;
    }
    tempsum=0;
    for(int i=mid+1;i<=end;i++)
    {
        tempsum+=arr[i];
        if(tempsum>rightsum)
            rightsum = tempsum;
    }

    return max(leftsum+rightsum,max(a1,a2));

}

int main()
{
    int n;
    cin>>n;

    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int ans = solve(arr,0,n-1);
    cout<<ans;
}

/*
 7
-1 2 3 5 -7 10 20
 */