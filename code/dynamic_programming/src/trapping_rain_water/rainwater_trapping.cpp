#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int left_highest[n];
	int right_highest[n];
	int l_high=arr[0];
    int i=0;
	int r_high=arr[n-1];
	for(i=0;i<n;i++){
		if(arr[i]>=l_high){
		left_highest[i]=arr[i];
		l_high=arr[i];
		}
		else
		left_highest[i]=l_high;
	}
    for(i=n-1;i>=0;i--){
        if(arr[i]>=r_high){
            right_highest[i]=arr[i];
            r_high=arr[i];
        }
        else
        right_highest[i]=r_high;
    }
    int water_saved=0;
    for(i=0;i<n;i++){
        water_saved+=min(left_highest[i],right_highest[i])-arr[i];
    }
    cout<<water_saved;
	return 0;
}