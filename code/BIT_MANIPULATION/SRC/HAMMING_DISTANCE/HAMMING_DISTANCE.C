#include<stdio.h>
#define BITS 8

void hamming(int ar1[],int ar2[]);
void input(int ar1[]);
int count_ham(int ar[]);
int n;

int main(){
	int ar1[BITS],ar2[BITS];
	printf("Enter the number of bits(max 8-bits):");
	scanf("%d",&n);
	printf("Enter a binary number(space between each bit and MAX 8-bit):");
	input(ar1);
	printf("Enter a binary number(space between each bit and MAX 8-bit):");
	input(ar2);
	hamming(ar1,ar2);
	return 0;
}

void input(int ar1[]){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&ar1[i]);
	}

}
int count_ham(int ar[]){
	int i,count=0;
	for(i=0;i<n;i++){
		if(ar[i]==1)
			count++;
	}
	return count;

}
void hamming(int ar1[],int ar2[]){
	int i,count;
	int res[BITS];
	for(i=0;i<n;i++){
		if((ar1[i]==1 && ar2[i]==0)||(ar1[i]==0 && ar2[i]==1)){
			res[i] = 1;
		}
		else{
			res[i] = 0;
		}
	}
	count = count_ham(res);
	printf("Hamming distance will be: %d",count);
	printf("\n");
}
