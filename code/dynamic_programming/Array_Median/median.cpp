#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,median;
    cout<<"Enter number of elements\n";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    if(arr.size()%2==0){
        median=arr[arr.size()/2]+arr[(arr.size()/2)-1]/2;
    }
    else
        median=arr[arr.size()/2];
    cout<<median;
    return 0;
}
