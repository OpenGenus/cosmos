#include <iostream>

using namespace std;

int f[100];

int find(int node)
{
	if(f[node] == node){
		return node;
	}
	return f[node] = find(f[node]); //path compression
}

int union_set(int x,int y)
{
	return f[find(x)]=find(y);
}

int main()
{
	int arr[10];

	for(int i=1;i<=10;i++){
		arr[i - 1] = i;
		f[i] = i;
	}

	union_set(1, 3);
	union_set(4, 5);
	union_set(1, 2);
	union_set(1, 5);
	union_set(2, 8);
	union_set(9, 10);
	union_set(1, 9);
	union_set(2, 7);
	union_set(3, 6);

	for(auto a : arr){
		cout<< a << "->" << f[a] <<"\n";
	}

	return 0;
}
