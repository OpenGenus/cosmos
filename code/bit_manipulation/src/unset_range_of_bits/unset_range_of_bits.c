#include<stdio.h>
int main(){
	
	int n,i,j;
	
	printf("\n Enter a number");
	scanf("%d",&n);
	
	//unset bit from i to j
	printf("\n Enter range ");
	scanf("%d %d",&j,&i);
	
	
	
	int a,b;
	
	a=-1<<(i+1);
	b=(1<<j)-1;
	
	int mask= a|b;
	
	int ans=n&mask;
	
	printf("\n New number generated after clearing bits from %d to %d : %d",j,i,ans);
	
}

/*
Input
Enter a number
31
Enter range 
1 
3
New number generated after clearing bits from 1 to 3 : 17
*/

