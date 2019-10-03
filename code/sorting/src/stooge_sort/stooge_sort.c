/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h>

void stooge_sort(int *input, int firs_num, int last_num)
{
	int temp = 0;
	int t = 0;
	if(input[firs_num] > input[last_num])
	{
		temp = input[firs_num];
		input[firs_num] = input[last_num];
		input[last_num] = temp;	
	}
	if((last_num - firs_num + 1) >= 3)
	{
		t = (last_num - firs_num + 1)/3;
		stooge_sort(input, firs_num, last_num - t);
		stooge_sort(input, firs_num + t, last_num);
		stooge_sort(input, firs_num, last_num - t);
	}
}



int main(void)
{
	int L[5] = {5, 3, 4, 1, 2};
	stooge_sort(L, 0, 4);
		
	int num;
	for(num = 0; num < 5; num++)
	{
		printf("\r\n %d", L[num]);
	}
	return 0;
}
	
