#include <stdio>
#include <algorithm>
using namespace std;
int size;
void swap(int *a,int *b){
	int t = *a; *a = *b; *b = t;
}
void print(int *a,int n){
	int i=0;
	for(;i<n;i++){printf("%d ",a[i]);}
	printf("\n");
}
int partition(int *a,int p,int q){
	int i = p,j;
	int x = a[q];
	for(j=p;j<q;j++){
		if(a[j]<x){
			i++;swap(a+j,a+i);
		}
	}
	swap(a+q,a+i);
	print(a,size);
	return i;
}
void quicksort(int *a,int p,int q){
	int pivot = -1;
	if(p>=q) return;
	pivot = partition(a,p,q);
	quicksort(a,p,pivot-1);
	quicksort(a,pivot+1,q);
}
int main(){
	int i,t;
	cin>>size;
	int *arr = (int*)malloc(sizeof(int)*size);
	for(i=0;i<size;i++){
		cin>>t;
		arr[i] = t;
	}
	quicksort(arr,0,size-1);
	free(arr);
	return 0;
}