#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v){
	int size = v.size();
	
	for(int i=0; i<size-1; i++){
	
		bool isSorted=1;
	
		for(int j=0; j<size-1-i; j++){
			if(v[j]>v[j+1]){
				swap(v[j],v[j+1]);
				isSorted = 0;
			}
		}
	
		for(int j=size-2; j>=i; j--){
			if(v[j]>v[j+1]){
				swap(v[j],v[j+1]);
				isSorted = 0;
			}
		}
	
		if(isSorted) break;
	
	}
	/*
	In this implementation,
	Modification From Normal Bubble Sort:
	1) Sorting From Both the Sides Simultaneously
	2) A variable isSorted which automatically breaks out of loop when elements get sorted reducing the total number of iterations.
	*/
}

int main(){
	int n;
	cout<<"Enter the number of elements you want to enter: "<<endl;
	cin>>n;
	vector<int> v(n);
	cout<<"Enter the elements: "<<endl;
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	
	bubbleSort(v);
	cout<<"Sorted Elements: "<<endl;
	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}