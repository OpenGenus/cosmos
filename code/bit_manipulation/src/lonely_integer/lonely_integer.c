/*
 *Part of Cosmos by OpenGenus Foundation
 *The Lonely Integer Problem
 *Given an array in which all the no. are present twice except one, find that lonely integer.
 */

#include <stdio.h>

int a[7] = {0,0,1,1,3,3,2};


int 
lonely(int n) {
	int no=0;

	for(int i=0;i<n;i++) {
		no^=a[i];
	}

	return (no);
}

int 
main() 
{
	int n=sizeof(a)/sizeof(int);
	printf("Lonely Integer is %d\n",lonely(n));

	return (0);
}