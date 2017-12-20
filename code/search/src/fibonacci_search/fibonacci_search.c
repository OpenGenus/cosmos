// search | fibonacci search | c
// Part of Cosmos by OpenGenus Foundation

/*
ar -> Array name
n -> Array size
secondPreceding -> Number at second precedence 
firstPreceding -> Number at first precedence
nextNum -> Fibonacci Number equal to or first greatest than the array size
range -> Eleminated range marker
*/

#include <stdio.h>
#include <stdlib.h>

int fibSearch(int ar[], int x, int n);
int min(int a, int b);

int main()
{
	int n;
	scanf("%d",&n);
	int ar[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	int x;
	scanf("%d",&x);
	int index = fibSearch(ar,x,n);
	if(index == -1){
		printf("Element not found.\n");
		return 0;
	}
	printf("Element found at index %d\n",index );
	return 0;
}

int fibSearch(int ar[], int x, int n)
{
	int secondPreceding = 0, firstPreceding = 1;
	int nextNum = secondPreceding + firstPreceding;
	while(nextNum < n){
		secondPreceding = firstPreceding;
		firstPreceding = nextNum;
		nextNum = secondPreceding + firstPreceding;
	} 
	int range = -1;
	while(nextNum > 1){
		int i = min(range + firstPreceding, n-1);
		if(x < ar[i]){
			nextNum = nextNum - firstPreceding;
			firstPreceding = firstPreceding - secondPreceding;
			secondPreceding = nextNum - firstPreceding;
		}
		else if(x > ar[i]){
			nextNum = firstPreceding;
			firstPreceding = secondPreceding;
			secondPreceding = nextNum - firstPreceding;
			range = i;
		}
		else{
			return i;
		}
	}
	if(firstPreceding && ar[range+1] == x){
		return range + 1;
	}
	return -1;
}
int min(int a, int b)
{
	if(a > b){
		return b;
	}
	else{
		return a;
	}
}
