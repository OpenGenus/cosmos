// Part of Cosmos by OpenGenus Foundation
#include "stdio.h"
#include "string.h"

int is_pandigital(long long number, int base);
int is_zeroless_pandigital(long long number, int base);
int check_number(long long number, int base);

int main(){
	long long number;
	int base;

	printf("Enter a number: ");
	scanf("%lld", &number);
	printf("Enter base (min:2,max:10): ");
	scanf("%d", &base);

	if(base < 2 || base > 10){
		printf("%d is not in [2,10] range.\n", base);
		return 1;
	}

	if(check_number(number, base)){
		if(is_pandigital(number, base)){
			printf("%lld is a pandigital number in base %d\n", number, base);
		}else{
			printf("%lld is not a pandigital number in base %d\n", number, base);
		}
		if(is_zeroless_pandigital(number, base)){
			printf("%lld is a zeroless pandigital number in base %d\n", number, base);
		}else{
			printf("%lld is not a zeroless pandigital number in base %d\n", number, base);
		}
	}else{
		printf("%lld is not a valid number in base %d\n", number, base);
	}

	return 0;
}

/**
 * this function checks if a number is pandigital in the given base
 * @param number number to be checked
 * @param base base to be checked
 * @return true if the number is pandigital in the given base, false otherwise
 */
int is_pandigital(long long number, int base){
	/* define an array to hold count of all digits */
	int digits[10], i;
	memset(digits, 0, sizeof(int)*10);

	/* for every digit in number, increment count by one */
	while(number > 0){
		int digit = number % 10;
		++digits[digit];
		number /= 10;
	}

	/* iterate over digits to see if there's an empty one, if so return false */
	for(i = 0; i < base; ++i)
		if(digits[i] == 0)
			return 0;

	/* if no empty digit found, return true */
	return 1;
}

/**
 * this function checks if a number is zeroless pandigital in the given base
 * @param number number to be checked
 * @param base base to be checked
 * @return true if the number is a zeroless pandigital in the given base, false otherwise
 */
int is_zeroless_pandigital(long long number, int base){
	/* define an array to hold count of all digits */
	int digits[10], i;
	memset(digits, 0, sizeof(int)*10);

	/* for every digit in number, increment count by one */
	while(number > 0){
		int digit = number % 10;
		if(digit == 0) return 0;
		++digits[digit];
		number /= 10;
	}

	/* iterate over digits to see if there's an empty one, if so return false */
	for(i = 1; i < base; ++i)
		if(digits[i] == 0)
			return 0;

	/* if no empty digit found, return true */
	return 1;
}

/* This function checks if given number is valid in the given base */
int check_number(long long number, int base){
	while(number > 0){
		int digit = number % 10;
		if(digit > base - 1) return 0;
		number /= 10;
	}
	return 1;
}
