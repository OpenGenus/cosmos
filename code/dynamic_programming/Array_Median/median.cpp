#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,median;
    vector<int> arr;
    cout<<"Enter number of elements\n";
    cin>>n;
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    if(arr.size()%2==0){
        median=arr[arr.size()/2]+arr[(arr.size()/2)-1]/2;
    }
    else{
        median=arr[arr.size()/2];
    }
    cout<<median;
    return 0;
}
