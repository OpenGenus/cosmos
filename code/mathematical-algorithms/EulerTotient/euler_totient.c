#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
/*
	Time Complexity - O(sqrtN)
*/
int eulerPhi(int n){
	int res = n;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			while(n%i == 0){
				n /= i;
			}
			res *= (i-1);
			res /= i;
		}
	}
	if(n != 1){
		res *= (n-1);
		res /= n;
	}
	return res;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", eulerPhi(n));
	return 0;
}
