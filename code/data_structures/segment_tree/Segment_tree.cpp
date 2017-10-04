#include <bits/stdc++.h>

using namespace std;

void createMinSegmentTree(int arr[],int sg[],int index,int begin,int end){
	//create the segment tree.
	if(begin == end){
		sg[index] = arr[begin];
		return;
	}
	int mid = (begin+end)/2;
	createMinSegmentTree(arr,sg,2*index,begin,mid);
	createMinSegmentTree(arr,sg,2*index+1,mid+1,end);
	sg[index] = min(sg[2*index],sg[2*index+1]);
	return;

}

int queryMinSegmentTree(int sg[],int l,int r,int index,int begin,int end){
	//querying the segment tree

	//complete overlap
	if(l <= begin && r >= end){
		return sg[index];
	}
	//no overlap
	else if(r<begin || l> end){
		return INT_MAX;
	}
	//partial overlap
	else{
		int mid = (begin+end)/2;
		return min(queryMinSegmentTree(sg,l,r,2*index,begin,mid),queryMinSegmentTree(sg,l,r,2*index+1,mid+1,end));
	}

}

void updateMinSegmentTree(int sg[],int l,int r,int index,int begin,int end,int update){

	if(begin == end && begin>=l && begin<=r){
		sg[index]+=update;
		return;
	}
	if(l>end || r<begin){
		return;
	}
	int mid = (begin+end)/2;
	updateMinSegmentTree(sg,l,r,2*index,begin,mid,update);
	updateMinSegmentTree(sg,l,r,2*index+1,mid+1,end,update);
	sg[index] = min(sg[2*index],sg[2*index+1]);
	return;


}

int main(){

	int n; cin >> n;

	int arr[n];

	for(int i=0;i<n;i++){
		arr[i] = rand()%n+1;
	}

	int sg[4*n]={};
	createMinSegmentTree(arr,sg,1,0,n-1);

	//print the original array
	for(int i =0;i<n;i++){
		cout << arr[i]<<" ";
	}
	cout << endl;

	int q; cin >> q;

	int l,r,option;
	while(q--){
		cin >> option;

		//option 1 to query the segment tree with range [l,r].
		if(option == 1){
			cin >> l >> r;
			cout << queryMinSegmentTree(sg,l,r,1,0,n-1)<<endl;
		}
		//option 2 to update the segment tree in range [l,r].
		else if(option == 2){
			int update;
			cin >> l >> r >> update;
			updateMinSegmentTree(sg,l,r,1,0,n-1,update);
		}
	}


	return 0;
}
