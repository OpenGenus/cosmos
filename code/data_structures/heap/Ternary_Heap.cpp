#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void minheapify(int H[],int i,int n){
	int left=3*i-1;
	int middle=3*i;
	int right=3*i+1;
	int smallest=i;
	if(left<=n && H[left]<H[smallest])
		smallest=left;
	if(middle<=n && H[middle]<H[smallest])
		smallest=middle;
	if(right<=n && H[right]<H[smallest])
		smallest=right;
	if(smallest!=i){
		swap(&H[i],&H[smallest]);
		minheapify(H,smallest,n);
	}
}

void buildheap(int H[],int n){
	for(int i=n;i>=0;i--){
		minheapify(H,i,n);
	}
}

void showheap(int H[],int n){
	for(int i=1;i<=n;i++){
		cout<<H[i]<<" ";
	}
}

void insert(int H[],int& n,int x){
	n=n+1;
	H[n]=x;
	int i=n;
	while(i>0 && H[i/3]>H[i]){
		swap(&H[i/3],&H[i]);
		i=i/3;
	}
}

int delete_min(int H[],int& n){
	int min=H[1];
	swap(&H[1],&H[n]);
	n=n-1;
	minheapify(H,1,n);
	return min;
}

void ksmallest(int H[],int& n,int k){
	int A[100];
	int p=n;
	for(int i=1;i<=n;i++){ //we will copy heap in another array
		A[i]=H[i];
	}
	int a;
	for(int j=0;j<k;j++){
		a=delete_min(A,p); //now we will call extract min k times in copied array
		cout<<a<<" ";	
	}
}

void ps1(int H[],int n,int a,int i){
	if(H[i]<=a && i<=n){
		cout<<H[i]<<" ";
	}
	else 
		return;
	ps1(H,n,a,3*i-1); //it will check now check in left node's children whether they are smaller than a or not
	ps1(H,n,a,3*i); //it will check now check in middle node's children whether they are smaller than a or not
	ps1(H,n,a,3*i+1); //it will check now check in right node's children whether they are smaller than a or not
}

//This function will call another function by providing th index of root node
void printsmall(int H[],int n,int a){
	ps1(H,n,a,1);
}

int main(){
	int n,k,a;
	int H[100];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>H[i];
	}
	cin>>k;
	cin>>a;
	buildheap(H,n);
	cout<<endl;
	showheap(H,n);
	cout<<endl;
	cout<<endl;
	ksmallest(H,n,k);
	cout<<endl;
	cout<<endl;
	showheap(H,n);
	cout<<endl;
	cout<<endl;
	printsmall(H,n,a);
	cout<<endl;
	cout<<endl;
	showheap(H,n);
	cout<<endl;
}