#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
int count_set_bits(int n){
	int c = 0;
	while (n) {
		c++;
		n&=(n-1);
	}
	return c;
}

int main() {	
	int n;
	scanf("%d", &n);
	printf("%d\n", count_set_bits(n));
	return 0;
}
