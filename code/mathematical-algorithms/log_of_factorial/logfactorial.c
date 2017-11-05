/* Part of Cosmos by OpenGenus Foundation */ 
#include <math.h>
#include <stdio.h>

double log_factorial(int n){
	double ans = 0;
	for(int i = 1; i <= n; i++)
		ans += log(i);
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%f",log_factorial(n));
	return 0;
}
