#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
  double timespent=0.0;
  clock_t start=clock();
    int a[] = {1,3,2,5,4,7,6,9,8,10,11,67,78,91,87,76,65};
    int n = sizeof(a) / sizeof(int);
int i, j, key;
for(i=1; i<nm; i++)
{
 key = a[i];
 j = i-1;
 
 while(j>=0 && key < a[j])
 {
 a[j+1] = a[j];
 j--;
 }
 a[j+1] = key;
}
for(i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
    }
    
clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    timespent += (double)(end - start) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds", timespent);}