/*#include<iostream>
#include<cmath>
using namespace std;*/

void printPrimesUptoN(int N){
	int ar[N] = {0};
	for(int i=2; i<=sqrt(N); i++){
		if(!ar[i]){
			for(int j=2; i*j<=N; j++)
				if(!ar[i*j])
					ar[i*j]=1;
		}
	}
	for(int i=2; i<=N; i++)
		if(!ar[i])
			cout<<i<<" ";
}
/*
int main(){
	printPrimesUptoN(120);
	return 0;
}
*/
