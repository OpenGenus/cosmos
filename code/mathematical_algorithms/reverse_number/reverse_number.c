#include<stdio.h>

int reverse_number(int n){
	int ans = 0;
	while (n != 0){
		ans *= 10;
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main(){
	int n;
	printf("Enter the number : ");
	scanf("%d",&n );
	printf("Reverse of %d is %d",n,reverse_number(n));

	return 0;
}
