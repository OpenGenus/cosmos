#include <math.h>
#include <stdio.h>

int log_factorial(int n){
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += log(i);
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",log_factorial(n));;
	return 0;
}
