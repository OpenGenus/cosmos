#include<iostream>
#include<climits>

/*
 * Part of Cosmos by OpenGenus Foundation
*/

using namespace std;
void countingSort(int arr[],int sortedA[],int n){
	int m=INT_MIN;
	for(int i=0;i<n;i++){
		if(arr[i]>m){
			m=arr[i];
		}
	}
	int freq[m+1]; //m is the maximum number in the array
	for(int i=0;i<=m;i++)
		freq[i]=0;
	for(int i=0;i<n;i++)
		freq[arr[i]]++;
	int j = 0;
    for(int i=0;i<=m;i++){
        int tmp=freq[i];
        while(tmp--){
            sortedA[j]=i;
            j++;
        }
    }
}
int main(){
	int arr[]={1,4,12,34,16,11,9,1,3,33,5};
	int size = sizeof(arr)/ sizeof(arr[0]);
	int sortedA[size+1]; // stores sorted array
   	countingSort(arr,sortedA,size);
   	cout<<"Sorted Array:  ";
   	for(int i=0;i<size;i++)
   		cout<<sortedA[i]<<" ";
   	return 0;
}
