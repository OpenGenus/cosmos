#include<bits/stdc++.h>
using namespace std;

void mergeit(vector<int> &arr, int start, int end){
    int mid = start+(end-start)/2;

    int len1 = mid-start+1;
    int len2 = end-mid;

    vector<int> first(len1);
    vector<int> second(len2);

    //copy values
    int k = start;
    for(int i = 0; i<len1; i++)
        first[i] = arr[k++];

    k = mid+1;
    for(int i = 0; i<len2; i++)
        second[i] = arr[k++];

    //merge two sorted array
    int index1 = 0, index2 = 0;
    k = start;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2])
            arr[k++] = first[index1++];
        else
            arr[k++] = second[index2++];
    }
    while(index1<len1){
        arr[k++] = first[index1++];
    }
    while(index2<len2){
        arr[k++] = second[index2++];
    }
}

void mergeSort(vector<int> &arr, int s, int e){
    //base case
    if(s>=e)
        return;

    int mid = s+((e-s)/2);

    //recursive call
    //for left subpart
    mergeSort(arr, s, mid);
    //for right subpart
    mergeSort(arr, mid+1, e);

    mergeit(arr, s, e);
}

int main(){
    int n;  cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    mergeSort(arr, 0, n-1);
    cout<<"The sorted array is:-"<<endl;
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<' ';
    cout<<endl;

 return 0;
}