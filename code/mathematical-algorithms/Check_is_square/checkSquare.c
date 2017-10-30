#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf(" %d", &n);
	int k = sqrt(n);
	if(k*k == n){
		printf("the number is a square\n");
	}else{
		printf("the number isnt a square\n");
	}
	return 0;
}
