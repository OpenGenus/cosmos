#include<iostream>
#include<vector>

using namespace std;

 int peakIndexInMountainArray(std::vector<int>& arr) {
        int n=arr.size();
        int s=0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
               mid = s + (e-s)/2;
        }
        return s;
    }
    int main(){
        vector<int> arr;
        arr.push_back(0);
        arr.push_back(1);
        arr.push_back(4);


        int ans = peakIndexInMountainArray(arr);
        cout<<ans<<endl;
    }